/*
 * jsAPI.h 
 * 2018/4/20 Keishin Ashihara
 */

/*
 * このプログラムはluaにinput_eventのAPIとして
 * 橋渡しをします。それだけ
 */

#pragma once

#include<linux/input.h>
#include<linux/joystick.h>
#include<sys/ioctl.h>
#include<sys/time.h>
#include<signal.h>
#include<errno.h>

#include<lua5.3/lua.h>
#include<lua5.3/lualib.h>
#include<lua5.3/lauxlib.h>

#include<string.h>

#include"uinput_set.h"
#include"DeviceEvent.h"
#include"input-event-lua.h"

#define JS_DEFAULT_PROFILE      "profile.lua"

#define JS_AXIS_VALUE_MAX       077777
#define JS_AXIS_VALUE_MIN       -077777 

#define DEFAULT_DEVICE_PATH     "/dev/input/js0"
#define DEFAULT_UINPUT_PATH     "/dev/uinput"
#define DEFAULT_ACT_INTERVAL    9000

#define LUA_DEFAULT_PROFILE     JS_DEFAULT_PROFILE
#define LUA_SET_CONFIG_TABLE    "config"
#define LUA_CONFIG_DEVICE_PATH  "path"
#define LUA_CONFIG_ACT_INTERVAL "interval"

#define LUA_ON_EVENT            "OnEvent"
#define LUA_BUTTON_ON_EVENT     "ButtonOnEvent"
#define LUA_AXIS_ON_EVENT       "AxisOnEvent"
#define LUA_ACTIVE_EVENT        "DeviceActive"
#define LUA_DEACTIVE_EVENT      "DeviceDeactive"

/*
 * 提供する関数
 */
int jsDevice_init(char* lua_profile);

int jsDevice_end();

int jsDevice_SendEvent(struct js_event js_ev);
