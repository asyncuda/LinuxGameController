#pragma once

#include<unistd.h>

#include<linux/input.h>
#include<linux/uinput.h>

#include<sys/ioctl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<string.h>
#include<stdio.h>

int jsDevice_OpenAndSetup_Uinput(char* filename);

void jsDevice_Uinput_SetBit(int fd);
