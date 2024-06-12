#pragma once

#include<linux/input-event-codes.h>
#include<linux/joystick.h>

#include<lua5.3/lua.h>
#include<lua5.3/lualib.h>
#include<lua5.3/lauxlib.h>

void event_luafunc_register(lua_State* L);

int Device_ABS_HAT0X(lua_State* L);
int Device_ABS_HAT0Y(lua_State* L);

int Device_BTN_A(lua_State* L);
int Device_BTN_B(lua_State* L);
int Device_BTN_X(lua_State* L);
int Device_BTN_Y(lua_State* L);
int Device_BTN_LEFT(lua_State* L);
int Device_BTN_RIGHT(lua_State* L);
int Device_BTN_MIDDLE(lua_State* L);
int Device_BTN_SELECT(lua_State* L);
int Device_BTN_START(lua_State* L);
int Device_BTN_MODE(lua_State* L);

int Device_KEY_LEFTMETA(lua_State *L);
int Device_KEY_LEFTALT(lua_State *L);
int Device_KEY_LEFTCTRL(lua_State* L);
int Device_KEY_ESC(lua_State *L); 
int Device_KEY_LEFTSHIFT(lua_State *L); 
int Device_KEY_ENTER(lua_State *L); 
int Device_KEY_RIGHT(lua_State *L); 
int Device_KEY_LEFT(lua_State *L); 
int Device_KEY_UP(lua_State *L); 
int Device_KEY_DOWN(lua_State *L); 
int Device_KEY_1(lua_State *L); 
int Device_KEY_2(lua_State *L); 
int Device_KEY_3(lua_State *L); 
int Device_KEY_4(lua_State *L); 
int Device_KEY_5(lua_State *L); 
int Device_KEY_6(lua_State *L); 
int Device_KEY_7(lua_State *L); 
int Device_KEY_8(lua_State *L); 
int Device_KEY_9(lua_State *L); 
int Device_KEY_0(lua_State *L); 
int Device_KEY_A(lua_State *L);
int Device_KEY_B(lua_State *L);
int Device_KEY_C(lua_State *L);
int Device_KEY_D(lua_State *L);
int Device_KEY_E(lua_State *L);
int Device_KEY_F(lua_State *L);
int Device_KEY_G(lua_State *L);
int Device_KEY_H(lua_State *L);
int Device_KEY_I(lua_State *L);
int Device_KEY_J(lua_State *L);
int Device_KEY_K(lua_State *L);
int Device_KEY_L(lua_State *L);
int Device_KEY_M(lua_State *L);
int Device_KEY_N(lua_State *L);
int Device_KEY_O(lua_State *L);
int Device_KEY_P(lua_State *L);
int Device_KEY_Q(lua_State *L);
int Device_KEY_R(lua_State *L);
int Device_KEY_S(lua_State *L);
int Device_KEY_T(lua_State *L);
int Device_KEY_U(lua_State *L);
int Device_KEY_V(lua_State *L);
int Device_KEY_W(lua_State *L);
int Device_KEY_X(lua_State *L);
int Device_KEY_Y(lua_State *L);
int Device_KEY_Z(lua_State *L);
