#include <stdio.h>
#include <pthread.h>

int counter = 0, tmr = 0;

int sleep_1 = 0, sleep_2 = 1;

int a[31];

void* foo(void* p){
	while(1){
		if(sleep_1) continue;
		if(counter == 20){
			sleep_1 = 1;
			sleep_2 = 0;
			printf("Time:%d\n", tmr++);
			continue;
		}
		a[counter] = counter;
		counter++;
	}
  	pthread_exit(NULL);
  	return NULL;
}

void* goo(void* p){
	while(1){
		if(sleep_2) continue;

		if(counter == 0){
			sleep_1 = 0;
			sleep_2 = 1;
			continue;
		}
		printf("%d ", a[counter--]);
	}
  	pthread_exit(NULL);
  	return NULL;
}

int main(){
	pthread_t thread_1, thread_2;
	pthread_create(&thread_1, NULL, foo, NULL);  
	pthread_create(&thread_2, NULL, goo, NULL); 
	while(1){

	}
  	return 0;
}
