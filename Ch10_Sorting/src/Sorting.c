#include "../include/Sorting.h"
#include "../include/Heap.h"
#include <stdio.h>
void BubbleSort(int arr[], int n){
	int temp;
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n-1-i; j++){
			if (arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
void SelectionSort(int arr[], int n){
	int temp;
	int i, j;
	int minIdx;
	for (i = 0; i < n-1; i++){
		minIdx = i;
		for (j = i+1; j < n; j++){
			if (arr[minIdx] > arr[j]){
				minIdx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}
void InsertionSort(int arr[], int n){
	int i, j;
	int val;
	for (i = 1; i < n; i++){
		val = arr[i];
		for (j = i-1; j >= 0; j--){
			if (arr[j] > val){
				arr[j+1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j+1] = val;
	}
}
int PriComp(int n1, int n2){
	return n2-n1;
}
void HeapSort(int arr[], int n){
	Heap heap;
	Init(&heap, PriComp);
	for (int i = 0; i < n; i++){
		Insert(&heap, arr[i]);
	}
	for (int i = 0; i < n; i++){
		arr[i] = Delete(&heap);
	}
}
void MergeArea(int arr[], int left, int mid, int right){
	int fIdx = left;
	int rIdx = mid+1;
	int* sortArr = (int*)malloc(sizeof(int) * (right+1)); // right - left + 1 ??
	int sIdx = left;
	while (fIdx <= mid && rIdx <= right){
		if (arr[fIdx] <= arr[rIdx]){
			sortArr[sIdx++] = arr[fIdx++];
		}
		else {
			sortArr[sIdx++] = arr[rIdx++];
		}
	}
	if (fIdx > mid){
		for (int i = rIdx; i <= right; i++){
			sortArr[sIdx++] = arr[i];
		}
	}
	else {
		for (int i = fIdx; i <= mid; i++){
			sortArr[sIdx++] = arr[i];
		}
	}
	
	// sortArr -> arr
	for (int i = left; i <= right; i++){
		arr[i] = sortArr[i];
	}
	free(sortArr);
}
void MergeSort(int arr[], int left, int right){
	int mid;
	if (left < right){
		mid = (left+right)/2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);

		MergeArea(arr, left, mid, right);
	}
}