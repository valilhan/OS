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

    int flag[256];

    int flag1=0;
    int flag2=0;


    while(1) {
        read(fp, &ev, sizeof(ev));

        if(ev.value==1 && ev.code==25){
            flag1=1;
        }
        if(ev.value==1 && ev.code==18){
            flag2=1;
        }
        if(ev.value==0 && ev.code==25){
            flag1=0;
        }
        if(ev.value==0 && ev.code==18){
            flag2=0;
        }
        if (flag1 == 1 && flag2 == 1) {
            printf ("I passed the Exam! \n");
        }
        //======================================
        if(ev.value==1 && ev.code==46){
            flag[0]=1;
        }
        if(ev.value==1 && ev.code==30){
            flag[1]=1;
        }
        if(ev.value==1 && ev.code==25){
            flag[2]=1;
        }


        if(ev.value==0 && ev.code==46){
            flag[0]=0;
        }
        if(ev.value==0 && ev.code==30){
            flag[1]=0;
        }
        if(ev.value==0 && ev.code==25){
            flag[2]=0;
        }

        if (flag[0] == 1 && flag[1] == 1 && flag[2] == 1) {
            printf ("Get some cappuccino! \n");
        }


        //================================
        if(ev.value==1 && ev.code==16){
            flag[3]=0;
        }
        if(ev.value==1 && ev.code==17){
            flag[4]=0;
        }
        if(ev.value==0 && ev.code==16){
            flag[3]=1;
        }
        if(ev.value==0 && ev.code==17){
            flag[4]=1;
        }
        if (flag[3] == 1 && flag[4] == 1) {
            printf ("Valihan get C! \n");
        }
    }
}
qwwqcappp