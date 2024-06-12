#include<unistd.h>

#include<linux/joystick.h>
#include<linux/input.h>
#include<sys/ioctl.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<errno.h>
#include<string.h>
#include<stdio.h>

#include"jsAPI.h"

int main(int argc, char *argv[]){

    if(argc != 2){
        puts("無効な引数です.");
        return -1;
    }

    int fd = 0;  
    while(1){
        if((fd = jsDevice_init(argv[1])) > 0) break;
        sleep(1);
    }
/*
    if(fd < 0){
        perror("jsGamePad.c: open failure");
        return -1;
    }
*/
    ioctl(fd, EVIOCGRAB, 1);

    struct js_event jsev;
    while (1)
    {
        if (read(fd, &jsev, sizeof(jsev)) != sizeof(jsev))
        {
            if(errno == EINTR){
                continue;
            }
            else{
                perror("joystick read error");
                break;
            }
        }

        if (jsev.type == JS_EVENT_BUTTON && jsev.number == 8){
            break;
        }
        jsDevice_SendEvent(jsev);
    }

    jsDevice_end();

    ioctl(fd, EVIOCGRAB, 0);
    close(fd);
    return 0;
}
