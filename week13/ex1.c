#include <stdbool.h>
#include <stdio.h>
int n,m;
void show(int E[m],int A[m],int C[n][m],int R[n][m]) {
    for (int i = 0; i < m; i++) {
        printf("%d ", E[i]);
    }
    printf("\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", C[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", R[i][j]);
        }
        printf("\n");
    }
}
int main() {
    FILE *in_file = fopen("C:/Users/Valihan/CLionProjects/untitled17/input.txt", "r");
    if (in_file == NULL) {
        printf("Error!");
    }
    scanf("%d", &n);
    scanf("%d", &m);
    int R[n][m];
    int C[n][m];
    int A[m];
    int E[m];

    for (int i = 0; i < m; i++) {
        fscanf(in_file, "%d", &E[i]);
    }
    for (int i = 0; i < m; i++) {
        fscanf(in_file, "%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(in_file, "%d", &C[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(in_file, "%d", &R[i][j]);
        }
    }
    bool marked[n];
    for(int i=0;i < n;i++){
        marked[i]=false;
    }
    int f1=0;
    int f2=0;
    while(true) {
       int op=0;
        for (int i = 0; i < n; i++) {

            if(!marked[i]) {
                int check = 1;
                for (int j = 0; j < m; j++) {
                    if (R[i][j] > A[j]) {
                        check = 0;
                        break;
                    }
                }
                if (check == 1) {
                    for (int j = 0; j < m; j++) {
                        if (R[i][j] <= A[j]) {
                            A[j] += C[i][j];
                        }
                    }
                    marked[i] = true;
                    op++;
                }
            }
        }

        if(op==0) {
            f1=1;
            break;
        }
        int exit=1;
        for(int i=0;i<m;i++){
            if(marked[i]==false) exit=0;
        }
        if(exit) {
            f2=1;
            break;
        }
    }
    if(f1){
        printf("Deadlock processes: ");
        for(int i=0;i<m;i++){
            if(marked[i]==false){
                printf("%d",i+1);
            }
        }
    }
    if(f2){
        printf("All processes are terminated");
    }
    /*
    for(int i=0;i<n;i++){
        printf("%d ",marked[i]);
    }
    printf("\n");

    show(E,A,C,R);
    */
    return 0;
}

