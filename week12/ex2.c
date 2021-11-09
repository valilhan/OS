#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *file_name="/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int fp = open(file_name, O_RDONLY); // read mode

    if (fp == -1) {fputs ("Reading error",stderr); exit (1);}
    struct input_event ev;
    while(1) {
        read(fp, &ev, sizeof(ev));
        if(ev.value==0){
            printf ("PRESSED %#06x (%d) \n", ev.code,ev.code);
        }
        else if(ev.value==1){
            printf("RELEASED %#06x (%d) \n",ev.code,ev.code);
        }

    }
}
