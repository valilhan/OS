#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//function to finding minimum
int min(int x, int y){
	if(x > y) return y;
	return x;
}

//my own function, i need to enter originalSize, newSize and size of Variable.(because i can not find size of pointer)
void *Realloc(void *ptr, int originalSize, int newSize, int sizeVariable){
	//allocated new pointer with newSize
	void *newptr = malloc(newSize*sizeVariable);
	//find minimum between this to sizes.
	size_t sz = min(originalSize, newSize)*sizeVariable;
	//then copy data from ptr to newptr, in range of sz(i can not assign elements because its void pointers)
	newptr = memcpy(newptr, ptr, sz);
	//dellocated old ptr
	free(ptr);
	//return newptr
	return newptr;
}

int main(){
	//i take it code from previous assignment to show my relloc.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	int* a1 = malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;
		
		printf("%d ",a1[i] );
	}

	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//*******************************

	a1=Realloc(a1, n1, n2, sizeof(a1[0]));

	//*******************************

	if(n2 > n1){
		for(int i = n1; i < n2; i++){
			a1[i] = 0;
		}
	}

	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}
	printf("\n");
	
	return 0;
}
