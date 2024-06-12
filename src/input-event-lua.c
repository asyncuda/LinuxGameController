#include"input-event-lua.h"

void event_luafunc_register(lua_State* L){

    lua_register(L, "ABS_HAT0X", Device_ABS_HAT0X);
    lua_register(L, "ABS_HAT0Y", Device_ABS_HAT0Y);

    lua_register(L, "BTN_A", Device_BTN_A);
    lua_register(L, "BTN_B", Device_BTN_B);
    lua_register(L, "BTN_X", Device_BTN_X);
    lua_register(L, "BTN_Y", Device_BTN_Y);
    lua_register(L, "BTN_LEFT", Device_BTN_LEFT);
    lua_register(L, "BTN_RIGHT", Device_BTN_RIGHT);
    lua_register(L, "BTN_MIDDDLE", Device_BTN_MIDDLE);
    lua_register(L, "BTN_SELECT", Device_BTN_SELECT);
    lua_register(L, "BTN_START", Device_BTN_START);
    lua_register(L, "BTN_MODE", Device_BTN_MODE);

    lua_register(L, "KEY_LEFTMETA", Device_KEY_LEFTMETA);
    lua_register(L, "KEY_LEFTALT", Device_KEY_LEFTALT);
    lua_register(L, "KEY_SUPER", Device_KEY_LEFTMETA);
    
    lua_register(L, "KEY_LEFTCTRL", Device_KEY_LEFTCTRL);
    lua_register(L, "KEY_ESC", Device_KEY_ESC);
    lua_register(L, "KEY_LEFTSHIFT", Device_KEY_LEFTSHIFT);
    lua_register(L, "KEY_ENTER", Device_KEY_ENTER);
    lua_register(L, "KEY_RIGHT", Device_KEY_RIGHT);
    lua_register(L, "KEY_LEFT", Device_KEY_LEFT);
    lua_register(L, "KEY_UP", Device_KEY_UP);
    lua_register(L, "KEY_DOWN", Device_KEY_DOWN);
    lua_register(L, "KEY_1", Device_KEY_1);
    lua_register(L, "KEY_2", Device_KEY_2);
    lua_register(L, "KEY_3", Device_KEY_3);
    lua_register(L, "KEY_4", Device_KEY_4);
    lua_register(L, "KEY_5", Device_KEY_5);
    lua_register(L, "KEY_6", Device_KEY_6);
    lua_register(L, "KEY_7", Device_KEY_7);
    lua_register(L, "KEY_8", Device_KEY_8);
    lua_register(L, "KEY_9", Device_KEY_9);
    lua_register(L, "KEY_0", Device_KEY_0);
    lua_register(L, "KEY_A", Device_KEY_A);
    lua_register(L, "KEY_B", Device_KEY_B);
    lua_register(L, "KEY_C", Device_KEY_C);
    lua_register(L, "KEY_D", Device_KEY_D);
    lua_register(L, "KEY_E", Device_KEY_E);
    lua_register(L, "KEY_F", Device_KEY_F);
    lua_register(L, "KEY_G", Device_KEY_G);
    lua_register(L, "KEY_H", Device_KEY_H);
    lua_register(L, "KEY_I", Device_KEY_I);
    lua_register(L, "KEY_J", Device_KEY_J);
    lua_register(L, "KEY_K", Device_KEY_K);
    lua_register(L, "KEY_L", Device_KEY_L);
    lua_register(L, "KEY_M", Device_KEY_M);
    lua_register(L, "KEY_N", Device_KEY_N);
    lua_register(L, "KEY_O", Device_KEY_O);
    lua_register(L, "KEY_P", Device_KEY_P);
    lua_register(L, "KEY_Q", Device_KEY_Q);
    lua_register(L, "KEY_R", Device_KEY_R);
    lua_register(L, "KEY_S", Device_KEY_S);
    lua_register(L, "KEY_T", Device_KEY_T);
    lua_register(L, "KEY_U", Device_KEY_U);
    lua_register(L, "KEY_V", Device_KEY_V);
    lua_register(L, "KEY_W", Device_KEY_W);
    lua_register(L, "KEY_X", Device_KEY_X);
    lua_register(L, "KEY_Y", Device_KEY_Y);
    lua_register(L, "KEY_Z", Device_KEY_Z);
}

int Device_ABS_HAT0X(lua_State *L) { lua_pushinteger(L, ABS_HAT0X); return 1;}
int Device_ABS_HAT0Y(lua_State *L) { lua_pushinteger(L, ABS_HAT0Y); return 1;}

int Device_BTN_A(lua_State *L) { lua_pushinteger(L, BTN_A); return 1;}
int Device_BTN_B(lua_State *L) { lua_pushinteger(L, BTN_B); return 1;}
int Device_BTN_X(lua_State *L) { lua_pushinteger(L, BTN_X); return 1;}
int Device_BTN_Y(lua_State *L) { lua_pushinteger(L, BTN_Y); return 1;}
int Device_BTN_LEFT(lua_State *L) { lua_pushinteger(L, BTN_LEFT); return 1;}
int Device_BTN_RIGHT(lua_State *L) { lua_pushinteger(L, BTN_RIGHT); return 1;}
int Device_BTN_MIDDLE(lua_State *L) { lua_pushinteger(L, BTN_MIDDLE); return 1;}
int Device_BTN_SELECT(lua_State *L) { lua_pushinteger(L, BTN_SELECT); return 1;}
int Device_BTN_START(lua_State *L) { lua_pushinteger(L, BTN_START); return 1;}
int Device_BTN_MODE(lua_State *L) { lua_pushinteger(L, BTN_MODE); return 1;}

int Device_KEY_LEFTMETA(lua_State *L){lua_pushinteger(L, KEY_LEFTMETA); return 1;}
int Device_KEY_LEFTALT(lua_State *L){lua_pushinteger(L, KEY_LEFTALT); return 1;}
int Device_KEY_LEFTCTRL(lua_State *L) { lua_pushinteger(L, KEY_LEFTCTRL); return 1;}
int Device_KEY_ESC(lua_State *L) { lua_pushinteger(L, KEY_ESC); return 1;}
int Device_KEY_LEFTSHIFT(lua_State *L) { lua_pushinteger(L, KEY_LEFTSHIFT); return 1;}
int Device_KEY_ENTER(lua_State *L) { lua_pushinteger(L, KEY_ENTER); return 1;}
int Device_KEY_RIGHT(lua_State *L) { lua_pushinteger(L, KEY_RIGHT); return 1;}
int Device_KEY_LEFT(lua_State *L) { lua_pushinteger(L, KEY_LEFT); return 1;}
int Device_KEY_UP(lua_State *L) { lua_pushinteger(L, KEY_UP); return 1;}
int Device_KEY_DOWN(lua_State *L) { lua_pushinteger(L, KEY_DOWN); return 1;}
int Device_KEY_1(lua_State *L) { lua_pushinteger(L, KEY_1); return 1;}
int Device_KEY_2(lua_State *L) { lua_pushinteger(L, KEY_2); return 1;}
int Device_KEY_3(lua_State *L) { lua_pushinteger(L, KEY_3); return 1;}
int Device_KEY_4(lua_State *L) { lua_pushinteger(L, KEY_4); return 1;}
int Device_KEY_5(lua_State *L) { lua_pushinteger(L, KEY_5); return 1;}
int Device_KEY_6(lua_State *L) { lua_pushinteger(L, KEY_6); return 1;}
int Device_KEY_7(lua_State *L) { lua_pushinteger(L, KEY_7); return 1;}
int Device_KEY_8(lua_State *L) { lua_pushinteger(L, KEY_8); return 1;}
int Device_KEY_9(lua_State *L) { lua_pushinteger(L, KEY_9); return 1;}
int Device_KEY_0(lua_State *L) { lua_pushinteger(L, KEY_0); return 1;}
int Device_KEY_A(lua_State *L) { lua_pushinteger(L, KEY_A); return 1;}
int Device_KEY_B(lua_State *L) { lua_pushinteger(L, KEY_B); return 1;}
int Device_KEY_C(lua_State *L) { lua_pushinteger(L, KEY_C); return 1;}
int Device_KEY_D(lua_State *L) { lua_pushinteger(L, KEY_D); return 1;}
int Device_KEY_E(lua_State *L) { lua_pushinteger(L, KEY_E); return 1;}
int Device_KEY_F(lua_State *L) { lua_pushinteger(L, KEY_F); return 1;}
int Device_KEY_G(lua_State *L) { lua_pushinteger(L, KEY_G); return 1;}
int Device_KEY_H(lua_State *L) { lua_pushinteger(L, KEY_H); return 1;}
int Device_KEY_I(lua_State *L) { lua_pushinteger(L, KEY_I); return 1;}
int Device_KEY_J(lua_State *L) { lua_pushinteger(L, KEY_J); return 1;}
int Device_KEY_K(lua_State *L) { lua_pushinteger(L, KEY_K); return 1;}
int Device_KEY_L(lua_State *L) { lua_pushinteger(L, KEY_L); return 1;}
int Device_KEY_M(lua_State *L) { lua_pushinteger(L, KEY_M); return 1;}
int Device_KEY_N(lua_State *L) { lua_pushinteger(L, KEY_N); return 1;}
int Device_KEY_O(lua_State *L) { lua_pushinteger(L, KEY_O); return 1;}
int Device_KEY_P(lua_State *L) { lua_pushinteger(L, KEY_P); return 1;}
int Device_KEY_Q(lua_State *L) { lua_pushinteger(L, KEY_Q); return 1;}
int Device_KEY_R(lua_State *L) { lua_pushinteger(L, KEY_R); return 1;}
int Device_KEY_S(lua_State *L) { lua_pushinteger(L, KEY_S); return 1;}
int Device_KEY_T(lua_State *L) { lua_pushinteger(L, KEY_T); return 1;}
int Device_KEY_U(lua_State *L) { lua_pushinteger(L, KEY_U); return 1;}
int Device_KEY_V(lua_State *L) { lua_pushinteger(L, KEY_V); return 1;}
int Device_KEY_W(lua_State *L) { lua_pushinteger(L, KEY_W); return 1;}
int Device_KEY_X(lua_State *L) { lua_pushinteger(L, KEY_X); return 1;}
int Device_KEY_Y(lua_State *L) { lua_pushinteger(L, KEY_Y); return 1;}
int Device_KEY_Z(lua_State *L) { lua_pushinteger(L, KEY_Z); return 1;}
