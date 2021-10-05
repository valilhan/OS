#include <stdio.h>
#include <stdlib.h> 

int main(){
	int n;
	scanf("%d", &n);
	//allocated memory with size n
	int *a = malloc(n*sizeof(int));

	//fill it by 0
	for(int i = 0; i < n; i++){
		a[i] = 0;
	}
	//print full array
	for(int i = 0; i < n; i++){
		printf("%d", a[i]);
	}
	free(a);
}
