#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 

int main(){
	//fork starts new child process with another process id.
	//then it will print from child and parent process. 
	int x = fork();
	int n = getpid();
	if(x != 0)
		printf("Hello from parent[PID - %d]\n", n);
	else
		printf("Hello from child[PID - %d]\n", n);
}
