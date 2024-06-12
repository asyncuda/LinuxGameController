#pragma once

#include<linux/input.h>
#include<linux/joystick.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

/*
 *filefd先へstruct input_eventデータを送る
 */  
void send_event(int filefd, int type, int code, int value);

void report_scroll(int mouse_fd, int up_y);

/**
 * 押す動作と離す動作を行う
 * send_event()を用いる
 */
void put_key(const int filefd, const int argev, struct input_event* ev);

