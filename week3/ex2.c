#include <stdio.h>

void bubble_sort(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main(){
	int a[] = {5, 4, 3, 2, 1};
	int n = sizeof(a)/sizeof(a[0]);
	bubble_sort(a, n);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}