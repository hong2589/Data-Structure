#include <stdio.h>
int Binary_Search(int arr[], int first, int last, int target){
	int mid;
	if (first > last) return -1;

	mid = (first + last) / 2;
	if (arr[mid] == target) {
		return mid;
	}
	else if (arr[mid] > target) {
		return Binary_Search(arr, first, mid-1, target);
	}
	else {
		return Binary_Search(arr, mid+1, last, target);
	}
}