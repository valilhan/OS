#include<stdio.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
 
int main(){
    int n;
    int at[1001], bt[1001], et[1001], wt[1001], tat[1001]; // all needed arrays
    int ttat = 0, twt = 0;
    printf("Enter number of process:\n"); //input all data, assuming that process given in arrival time order
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("Enter arrival time and burst time of %d process ", i);
        scanf("%d%d", &at[i], &bt[i]);
    }
    int tmr = 0; // my timer
    for(int i = 1; i <= n; i++){
        wt[i] = max(0, tmr - at[i]); // my process will start exucte at time or at it's arrival time, depending when it arrived to system
        tat[i] = wt[i] + bt[i]; // calculating total around time 
        tmr = max(tmr + bt[i], at[i] + bt[i]); // depending when i started execute my tmr will change its value to ending time
        et[i] = tmr; // ending time
        ttat += tat[i]; //total total around time 
        twt += wt[i]; //total waiting time 
        printf("P[%d]:Waiting time %d, Turn around time %d, Completion time %d\n", i, wt[i], tat[i], et[i]); //printing information about all times.
    }
    //printing average times.
    printf("Average total around time: %f\n", ttat * 1.0 / n);
    printf("Average waiting time: %f\n", twt * 1.0 / n);
    return 0;
}
