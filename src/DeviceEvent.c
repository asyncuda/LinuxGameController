#include"DeviceEvent.h"

void send_event(int filefd, int type, int code, int value){

    struct input_event event;

    event.type = type;
    event.code = code;
    event.value = value;
    gettimeofday(&event.time, NULL);
    //printf("write:%d:%d:%d\n", type, code, value);

    if(write(filefd, &event, sizeof(event)) < sizeof(event)){
        perror("send_event write error");
    }

    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    gettimeofday(&event.time, NULL);

    if(write(filefd, &event, sizeof(event)) < sizeof(event)){
        perror("send_event write error");
    }
}

void report_scroll(int mouse_fd, int up_y){

    send_event(mouse_fd, EV_REL, REL_WHEEL, up_y);
}

void put_key(const int filefd, const int argev, struct input_event* ev){

    for(int i = 0; i < argev; i++){
        send_event(filefd, ev[i].type, ev[i].code, 1);
    }
    for(int i = 0; i < argev; i++){
        send_event(filefd, ev[i].type, ev[i].code, 0);
    }
    send_event(filefd, EV_SYN, SYN_REPORT, 0);
}
