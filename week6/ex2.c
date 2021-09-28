#include<stdio.h>
#include <stdlib.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
 
int n;
int at[1001], bt[1001], et[1001], wt[1001], tat[1001], rem[1001]; //all needed arrays
int ttat = 0, twt = 0;

int Find(int tmr){ //Function which function should executes depending on shortest burst time
    int mn = 11111111, index = -1;
    for(int i = 1; i <= n; i++){ 
        if(tmr >= at[i] && rem[i] > 0){ //Checking if process come before timer and is it executes fully
            if(bt[i] < mn){ //Finding minimum burst time process
                mn = bt[i];
                index = i;
            }
        }
    }
    //returning its index
    return index;
}

int main(){
    printf("Enter number of process:\n"); //input all data
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("Enter arrival time and burst time of %d process ", i);
        scanf("%d%d", &at[i], &bt[i]);
        rem[i] = bt[i]; //temorary array, that saves reminder burst time
    }
    int completed = 0, tmr = 0; // number of completed process and timer.
    //My code go trought all time starting from one, until all process will not completed. And finding which process it should executed at each time.
    while(completed < n){
        int index = Find(tmr); //Finding process that should execute
        if(index != -1){ //If this process exists(if exist process that not fully executes before tmr)
            rem[index] --; //decreasing reminder
            if(rem[index] == 0){ //if process fully executes, it will increase completed process and save ending time
                et[index] = tmr + 1;
                completed ++;
            }
        }  
        tmr ++; // increasing timer
    }
    for(int i = 1; i <= n; i++){ //Find all other times by formula and print
        tat[i] = et[i] - at[i];
        wt[i] = tat[i] - bt[i];
        ttat += tat[i];
        twt += wt[i];
        printf("P[%d]:Waiting time %d, Turn around time %d, Completion time %d\n", i, wt[i], tat[i], et[i]);
    }
    printf("Average total around time: %f\n", ttat * 1.0 / n);
    printf("Average waiting time: %f\n", twt * 1.0 / n);
    return 0;
}
