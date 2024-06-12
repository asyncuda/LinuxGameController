#include"uinput_set.h"

int jsDevice_OpenAndSetup_Uinput(char* filename){

    int fd = -1;
    struct uinput_setup usetup;

    fd = open(filename, O_RDWR | O_NONBLOCK);
    if(fd < 0){
        perror("Uinput open error");
        return fd;
    }

    memset(&usetup, 0, sizeof(usetup));
    strcpy(usetup.name, "usual-UserInputDevice");

    jsDevice_Uinput_SetBit(fd);

    ioctl(fd, UI_DEV_SETUP, &usetup);
    ioctl(fd, UI_DEV_CREATE);

    usleep(100000);

    return fd;
}

void jsDevice_Uinput_SetBit(int fd){

    ioctl(fd, UI_SET_EVBIT, EV_KEY);
    ioctl(fd, UI_SET_KEYBIT, KEY_ESC);
    ioctl(fd, UI_SET_KEYBIT, KEY_LEFTMETA);
    ioctl(fd, UI_SET_KEYBIT, KEY_LEFTALT);
    ioctl(fd, UI_SET_KEYBIT, KEY_ENTER);
    ioctl(fd, UI_SET_KEYBIT, KEY_LEFTSHIFT);
    ioctl(fd, UI_SET_KEYBIT, KEY_LEFTCTRL);
    ioctl(fd, UI_SET_KEYBIT, BTN_LEFT);
    ioctl(fd, UI_SET_KEYBIT, BTN_RIGHT);
    ioctl(fd, UI_SET_KEYBIT, BTN_MIDDLE);

    ioctl(fd, UI_SET_KEYBIT, KEY_RIGHT);
    ioctl(fd, UI_SET_KEYBIT, KEY_LEFT);
    ioctl(fd, UI_SET_KEYBIT, KEY_UP);
    ioctl(fd, UI_SET_KEYBIT, KEY_DOWN);

    ioctl(fd, UI_SET_KEYBIT, KEY_A);
    ioctl(fd, UI_SET_KEYBIT, KEY_B);
    ioctl(fd, UI_SET_KEYBIT, KEY_C);
    ioctl(fd, UI_SET_KEYBIT, KEY_D);
    ioctl(fd, UI_SET_KEYBIT, KEY_E);
    ioctl(fd, UI_SET_KEYBIT, KEY_F);
    ioctl(fd, UI_SET_KEYBIT, KEY_G);
    ioctl(fd, UI_SET_KEYBIT, KEY_H);
    ioctl(fd, UI_SET_KEYBIT, KEY_I);
    ioctl(fd, UI_SET_KEYBIT, KEY_J);
    ioctl(fd, UI_SET_KEYBIT, KEY_K);
    ioctl(fd, UI_SET_KEYBIT, KEY_L);
    ioctl(fd, UI_SET_KEYBIT, KEY_M);
    ioctl(fd, UI_SET_KEYBIT, KEY_N);
    ioctl(fd, UI_SET_KEYBIT, KEY_O);
    ioctl(fd, UI_SET_KEYBIT, KEY_P);
    ioctl(fd, UI_SET_KEYBIT, KEY_Q);
    ioctl(fd, UI_SET_KEYBIT, KEY_R);
    ioctl(fd, UI_SET_KEYBIT, KEY_S);
    ioctl(fd, UI_SET_KEYBIT, KEY_T);
    ioctl(fd, UI_SET_KEYBIT, KEY_U);
    ioctl(fd, UI_SET_KEYBIT, KEY_V);
    ioctl(fd, UI_SET_KEYBIT, KEY_W);
    ioctl(fd, UI_SET_KEYBIT, KEY_X);
    ioctl(fd, UI_SET_KEYBIT, KEY_Y);
    ioctl(fd, UI_SET_KEYBIT, KEY_Z);

    ioctl(fd, UI_SET_EVBIT, EV_REL);
    ioctl(fd, UI_SET_RELBIT, REL_WHEEL);
    ioctl(fd, UI_SET_RELBIT, REL_X);
    ioctl(fd, UI_SET_RELBIT, REL_Y);
}
