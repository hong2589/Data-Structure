#include <stdio.h>
int BinarySearch(int arr[], int first, int last, int target){
	int mid = (first+last)/2;
	if (first > last){
		return -1;
	}
	if (arr[mid] == target){
		return mid;
	}
	else if (arr[mid] > target){
		return BinarySearch(arr, first, mid-1, target);
	}
	else {
		return BinarySearch(arr, mid+1, last, target);
	}
}