#include <stdio.h>
#include "../include/Sorting.h"
void ShowArr(int arr[], int n){
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(){
	int arr[] = {3, 2, 4, 1, 6};
	int n = sizeof(arr)/sizeof(int);
	// BubbleSort(arr, n);
	// SelectionSort(arr, n);
	// InsertionSort(arr, n);
	HeapSort(arr, n);
	ShowArr(arr, n);

	return 0;
}