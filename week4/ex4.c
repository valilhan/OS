#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <string.h>
#include <unistd.h> 

int main(){
	char c[100001];
	while(1){
		//it reads command from user and pass it through system function, that use it as shell command. 
		//not depending with parameters or not system works for both
		fgets(c, sizeof(c), stdin);
		printf("%s", c);
		if(strcmp(c, "gg\n") == 0){
			break;
		}
		system(c);
	}
}
