#include <stdio.h>
#include <Pthread.h>
#include <stdlib.h>
using namespace std;

typedef struct  {

    pthread_t  thread_id;
    int thread_num;
    char * string;

} thread_info;

void* job (void*args){
    thread_info *t=(thread_info*)args;
    printf("Hello world \n");
}
int main(){
    thread_info* tinfo;
    int N;
    printf("N= ");
    scanf("%d",&N);

    tinfo= static_cast<thread_info *>(calloc(N, sizeof(thread_info)));
    for(int i=0;i<N;i++){

        pthread_create((&tinfo[i].thread_id), NULL,job, &tinfo[i]);

    }

    exit(EXIT_SUCCESS);
}
