// C program for implementation of Bubble sort 
#include <stdio.h> 

void swap(int *x, int *y) 
{ 
	int tp = *x; 
	*x = *y; 
	*y = tp; 
} 

// A function to implement bubble sort 
void bubbleSort(int arr[]) 
{ 
  int n = *(&arr + 1) - arr;
int i, j; 
for (i = 0; i < n; i++)	 
	for (j = 0; j < n-i; j++) 
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
} 

// Driver program to test above functions 
int main() 
{ 
  	    int n = 0;

    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf ("%d", &arr[i]);
    }
	bubbleSort(arr); 
   for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

	return 0; 
} 
