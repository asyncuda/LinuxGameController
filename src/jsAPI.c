/*
 * jsAPI.c 
 * 2018/4/20 -> 30 Keishin Ashihara
 */

/*
 * このプログラムはluaにinput_eventのAPIとして
 * 橋渡しをします。
 * jsDevice_initによりluaのファイルの読み込みを行います。
 * 同時に、LUA_ACTIVE_EVENTで設定されたluaの関数を呼び出します
 * 
 * 初期化後、ACT_INTERVALマイクロ秒おきに
 * マウスホイールとカーソル移動イベントを呼び出します。
 * これは、移動量が0の時に書き込みは発生しません。
 * 
 */

#include"jsAPI.h"

static lua_State* L = NULL;
static int uinput_fd = -1;
static int js_fd = -1;

struct {
    
    //depend lua_Stete
    char js_path[256];
    int act_interval;

}config;

struct {

    //depend js_fd;
    char axes;
    char buttons;
    int version;
    char name[30];

}DeviceState;

struct {

    int x;
    int y;
    int wheel;

} MouseMove;

/*
 * luaから値を受け取ることはすべてget_profileに書く
 */

static int get_profileinfo(char *lua_profile);
static void init_luaConfig();
static void set_luaConfig();

static void init_FileDescriptor();
static int set_FileDescriptor();
static void set_DeviceState();
static void set_MouseMove();

static void set_event_handler();
static void end_event_handler();
static void alarm_handler(int signum);

static void eh_MouseMoving();
static void eh_MouseWheeling();

static void jsDevicelua_register();
static int jsDevicelua_AxisValueMax(lua_State *l);
static int jsDevicelua_AxisValueMin(lua_State *l);
static int jsDevicelua_DeviceName(lua_State *l);
static int jsDevicelua_InputButtonEvent(lua_State *l);
static int jsDevicelua_PressButton(lua_State *l);
static int jsDevicelua_ReleaseButton(lua_State *l);
static int jsDevicelua_KeyClick(lua_State *l);
static int jsDevicelua_MouseClick(lua_State *l);
static int jsDevicelua_MoveCursorTo(lua_State *l);
static int jsDevicelua_MovingCursor(lua_State *l);
static int jsDevicelua_MovingCursorX(lua_State *l);
static int jsDevicelua_MovingCursorY(lua_State *l);
static int jsDevicelua_StopCursor(lua_State *l);
static int jsDevicelua_StopCursorX(lua_State *l);
static int jsDevicelua_StopCursorY(lua_State *l);
static int jsDevicelua_MouseWheeling(lua_State *l);
static int jsDevicelua_MouseWheel(lua_State *l);
static int jsDevicelua_StopWheeling(lua_State *l);

int jsDevice_init(char* lua_profile){
   
    get_profileinfo(lua_profile);

    //uinput, joystick, lua_profle,それぞれのファイルを開く
    if(set_FileDescriptor()){
        perror("File set failure");
        return -1;
    }

    set_DeviceState();
    set_MouseMove();
    set_event_handler();

    //luaにイベントを送信
    lua_getglobal(L, LUA_ACTIVE_EVENT);
    if(lua_pcall(L, 0, 0, 0)){
        perror("jsAPI.c: lua Active() call error");
        return -1;
    }

    return js_fd;
}

int jsDevice_end(){
    
    //luaにイベントを送信
    lua_getglobal(L, LUA_DEACTIVE_EVENT);
    if(lua_pcall(L, 0, 0, 0)){
        perror("lua Deactive() call failure");
        return -1;
    }

    end_event_handler();
    close(uinput_fd);
    lua_close(L);
    
    init_FileDescriptor();

    return 0;
}

int jsDevice_SendEvent(struct js_event js_ev){

    if(js_ev.type & JS_EVENT_INIT) return 0;

    if(js_ev.type == JS_EVENT_BUTTON){

        lua_getglobal(L, LUA_BUTTON_ON_EVENT);
        lua_pushinteger(L, js_ev.number);
        lua_pushinteger(L, js_ev.value);
        if (lua_pcall(L, 2, 0, 0))
        {
            perror("jsAPI.c: sendEvent Button run error");
            return -1;
        }

    }else if(js_ev.type == JS_EVENT_AXIS){

        lua_getglobal(L, LUA_AXIS_ON_EVENT);
        lua_pushinteger(L, js_ev.number);
        lua_pushinteger(L, js_ev.value);
        if (lua_pcall(L, 2, 0, 0))
        {
            perror("jsAPI.c: sendEvent Axis run error");
            return -1;
        }
    }

    return 0;
}

/*
 * profileからlua_Stateを初期化し、
 * config table からconfig構造体の設定を行う
 */
static int get_profileinfo(char* lua_profile){
    
    //lua_State *L
    L = luaL_newstate();
    luaL_openlibs(L);
    event_luafunc_register(L);
    jsDevicelua_register();

    if(luaL_dofile(L, lua_profile)){
        perror("jsAPI.c: lua file read error");
        init_FileDescriptor();
        return -1;
    }   

    set_luaConfig();

    return 0;
}

static void init_luaConfig(){

    memset(config.js_path, 0, sizeof(config.js_path));
    strncpy(config.js_path, DEFAULT_DEVICE_PATH, sizeof(config.js_path) -1);

    config.act_interval = DEFAULT_ACT_INTERVAL;
}

static void set_luaConfig(){

    init_luaConfig();

    lua_getglobal(L, LUA_SET_CONFIG_TABLE);
    lua_getfield(L, -1, LUA_CONFIG_DEVICE_PATH);
    lua_getfield(L, -2, LUA_CONFIG_ACT_INTERVAL);

    if(!lua_isnil(L, -2)){
        memset(config.js_path, 0, sizeof(config.js_path));
        strncpy(config.js_path, luaL_checkstring(L, -2), sizeof(config.js_path) -1);
    }
    if(!lua_isnil(L, -1)){
        config.act_interval = luaL_checkinteger(L, -1);
    }
}

/*
 * js_fd はconfig.device_pathの情報を元に、
 * uinput_fd はデフォルトの情報を元にファイルを開く
 */
static void init_FileDescriptor(){
    
    L = NULL;
    uinput_fd = -1;
    js_fd = -1;
}

static int set_FileDescriptor(){

    //js_fd
    js_fd = open(config.js_path, O_RDWR);
    if(js_fd < 0){
        perror("jsAPI.c: joystick event file open failure");
        init_FileDescriptor();
        return -1;
    }

    //uinput_fd
    uinput_fd = jsDevice_OpenAndSetup_Uinput(DEFAULT_UINPUT_PATH);
    if(uinput_fd < 0){
        perror("jsAPI.c: uinput open failure");
        init_FileDescriptor();
        return -1;
    }

    return 0;
}

static void set_DeviceState(){

    if(js_fd < 0) return;

    ioctl(js_fd, JSIOCGAXES, &DeviceState.axes);
    ioctl(js_fd, JSIOCGBUTTONS, &DeviceState.buttons);
    ioctl(js_fd, JSIOCGVERSION, &DeviceState.version);
    if(ioctl(js_fd, JSIOCGNAME(sizeof(DeviceState.name)), DeviceState.name) < 0){
        strncpy(DeviceState.name, "Unknown", sizeof(DeviceState.name));
    }
}

static void set_MouseMove(){

    MouseMove.x = 0;
    MouseMove.y = 0;
    MouseMove.wheel = 0;
}

static void set_event_handler(){

    struct itimerval itimer;
    itimer.it_interval.tv_sec = 0;
    itimer.it_interval.tv_usec = config.act_interval;
    itimer.it_value.tv_sec = 0;
    itimer.it_value.tv_usec = config.act_interval;

    setitimer(ITIMER_REAL, &itimer, NULL);

    struct sigaction act;
    memset(&act, 0, sizeof(sigaction));
    act.sa_handler = alarm_handler;
    act.sa_flags = 0;
    sigaction(SIGALRM, &act, NULL);
}

static void end_event_handler(){

    struct itimerval itimer;
    itimer.it_interval.tv_sec = 0;
    itimer.it_interval.tv_usec = 0;
    itimer.it_value.tv_sec = 0;
    itimer.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &itimer, NULL);
}

static void alarm_handler(int signum){
    eh_MouseMoving();
    eh_MouseWheeling();
}

static void eh_MouseMoving(){

    if(MouseMove.x){
       send_event(uinput_fd, EV_REL, REL_X, MouseMove.x);
    }
    if(MouseMove.y){
       send_event(uinput_fd, EV_REL,  REL_Y, MouseMove.y);
    }
}

static void eh_MouseWheeling(){
    if(MouseMove.wheel){
        send_event(uinput_fd, EV_REL, REL_WHEEL, MouseMove.wheel);
    }
}

static void jsDevicelua_register(){

    lua_register(L, "AXIS_VALUE_MAX", jsDevicelua_AxisValueMax);
    lua_register(L, "AXIS_VALUE_MIN", jsDevicelua_AxisValueMin);
    lua_register(L, "DeviceName", jsDevicelua_DeviceName);
    lua_register(L, "InputButtonEvent", jsDevicelua_InputButtonEvent);
    lua_register(L, "PressButton", jsDevicelua_PressButton);
    lua_register(L, "ReleaseButton", jsDevicelua_ReleaseButton);
    lua_register(L, "KeyClick", jsDevicelua_KeyClick);
    lua_register(L, "MouseClick", jsDevicelua_MouseClick);
    lua_register(L, "MoveCursorTo", jsDevicelua_MoveCursorTo);
    lua_register(L, "MovingCursor", jsDevicelua_MovingCursor);
    lua_register(L, "MovingCursorX", jsDevicelua_MovingCursorX);
    lua_register(L, "MovingCursorY", jsDevicelua_MovingCursorY);
    lua_register(L, "StopCursor", jsDevicelua_StopCursor);
    lua_register(L, "StopCursorX", jsDevicelua_StopCursorX);
    lua_register(L, "StopCursorY", jsDevicelua_StopCursorY);
    lua_register(L, "MouseWheeling", jsDevicelua_MouseWheeling);
    lua_register(L, "StopWheeling", jsDevicelua_StopWheeling);
    lua_register(L, "MouseWheel", jsDevicelua_MouseWheel);

}

static int jsDevicelua_AxisValueMax(lua_State *l){

    lua_pushinteger(l, JS_AXIS_VALUE_MAX);

    return 1;
}

static int jsDevicelua_AxisValueMin(lua_State *l){

    lua_pushinteger(l, JS_AXIS_VALUE_MIN);

    return 1;
}

static int jsDevicelua_DeviceName(lua_State *l){

    if(DeviceState.name == NULL){
        lua_pushnil(l);
    }else{
        lua_pushstring(l, DeviceState.name);
    }

    return 1;
}

static int jsDevicelua_InputButtonEvent(lua_State *l){

    return 0;
}

static int jsDevicelua_PressButton(lua_State *l){

    int code = luaL_checkinteger(l, -1);
    if(code == 0){
        perror("jsAPI.c: PressButton less argument");
        return 0;
    }

    send_event(uinput_fd, EV_KEY, code, 1);

    return 0;
}

static int jsDevicelua_ReleaseButton(lua_State *l){
 
    int code = luaL_checkinteger(l, -1);
    if(code == 0){
        return 0;
    }

    send_event(uinput_fd, EV_KEY, code, 0);

    return 0;
}

static int jsDevicelua_KeyClick(lua_State *l){

    int code = luaL_checkinteger(l, -1);
    if(code == 0){
        return 0;
    }

    send_event(uinput_fd, EV_KEY, code, 1);
    send_event(uinput_fd, EV_KEY, code, 0);

    return 0;
}

static int jsDevicelua_MouseClick(lua_State *l){

    send_event(uinput_fd, EV_KEY, BTN_LEFT, 1);
    send_event(uinput_fd, EV_KEY, BTN_LEFT, 0);

    return 0;
}

static int jsDevicelua_MoveCursorTo(lua_State *l){

    return 0;
}

static int jsDevicelua_MovingCursor(lua_State *l){

    int mx = luaL_checkinteger(l, -2);
    int my = luaL_checkinteger(l, -1);

    if(!(mx | my)){
        return 0;
    }

    MouseMove.x = mx;
    MouseMove.y = my;

    return 0;
}

static int jsDevicelua_MovingCursorX(lua_State *l){

    int mx = luaL_checkinteger(l, -1);

    MouseMove.x = mx;

    return 0;
}

static int jsDevicelua_MovingCursorY(lua_State *l){

    int my = luaL_checkinteger(l, -1);

    MouseMove.y = my;

    return 0;
}

static int jsDevicelua_StopCursor(lua_State *l){

    MouseMove.x = 0;
    MouseMove.y = 0;

    return 0;
}

static int jsDevicelua_StopCursorX(lua_State *l){

    MouseMove.x = 0;

    return 0;
}
 
static int jsDevicelua_StopCursorY(lua_State *l){

    MouseMove.y = 0;

    return 0;
}
    
static int jsDevicelua_MouseWheeling(lua_State *l){

    int wheel = luaL_checkinteger(l, -1);

    MouseMove.wheel = -1 * wheel;

    return 0;
}

static int jsDevicelua_StopWheeling(lua_State *l){

    MouseMove.wheel = 0;

    return 0;
}

static int jsDevicelua_MouseWheel(lua_State *l){

    int wheel = luaL_checkinteger(l, -1);

    send_event(uinput_fd, EV_REL, REL_WHEEL, -1 * wheel);

    return 0;
}
