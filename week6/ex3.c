/*
Checked all scheduling algorithms for test (For third problem taked quantum as 3)
5
0 3  
1 8 
2 6 
4 4 
5 2 
Then
FCFS alogrithm gives:
P[1]:Waiting time 0, Turn around time 3, Completion time 3
P[2]:Waiting time 2, Turn around time 10, Completion time 11
P[3]:Waiting time 9, Turn around time 15, Completion time 17
P[4]:Waiting time 13, Turn around time 17, Completion time 21
P[5]:Waiting time 16, Turn around time 18, Completion time 23
Average total around time: 12.600000
Average waiting time: 8.000000
Shortest job first algorithm gives:
P[1]:Waiting time 0, Turn around time 3, Completion time 3
P[2]:Waiting time 14, Turn around time 22, Completion time 23
P[3]:Waiting time 7, Turn around time 13, Completion time 15
P[4]:Waiting time 2, Turn around time 6, Completion time 10
P[5]:Waiting time 0, Turn around time 2, Completion time 7
Average total around time: 9.200000
Average waiting time: 4.600000
Round robin algorithm gives:
P[1]:Waiting time 0, Turn around time 2, Completion time 2
P[2]:Waiting time 13, Turn around time 21, Completion time 22
P[3]:Waiting time 11, Turn around time 17, Completion time 19
P[4]:Waiting time 12, Turn around time 16, Completion time 20
P[5]:Waiting time 6, Turn around time 8, Completion time 13
Average total around time: 12.800000
Average waiting time: 8.400000
We can see that shortest job first algorithm is most effective in terms of Average total around time and Average waiting time.
Round robin algoritms effectivness can change depending on quantum number.
*/
#include<stdio.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
 
int main(){
    int n, q;
    int at[1001], bt[1001], et[1001], wt[1001], tat[1001], rem[1001]; //all needed arrays
    int ttat = 0, twt = 0;
    printf("Enter number of process: ");
    scanf("%d", &n); //Input all data, assuming that process giving in order of it's arriveness.
    for(int i = 1; i <= n; i++){
        printf("Enter arrival time and burst time of %d process ", i);
        scanf("%d%d", &at[i], &bt[i]);
        rem[i] = bt[i]; //temorary array, that saves reminder burst time
    }
    printf("Enter quantum number ");
    scanf("%d", &q); //input quantum number
    int completed = 0, tmr = 0;
    //loop while all process completed
    while(completed < n){ // number of completed process and timer.
        int ch = 0; // checking is action happened
        for(int i = 1; i <= n; i++){
            if(at[i] <= tmr && rem[i] > 0){ //if process arived before and it not completed  
                ch = 1; //saying that action happened
                if(rem[i] > q){ //if reminder is greater than qunatum number, then it will be executed at least one time
                    rem[i] -= q; //decreasing reminder
                    tmr += q; //increasing timer
                } 
                else{
                    tmr += rem[i]; //execute process fully and saying that it complete.
                    rem[i] = 0; 
                    et[i] = tmr; //save ending time
                    completed ++;
                }
            }
        }
        if(!ch) tmr++; //if no action happened then increasing, for not infinitely looped
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
