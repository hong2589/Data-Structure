#ifndef __SORTING_H__
#define __SORTING_H__
#include "../include/Heap.h"

void BubbleSort(int arr[], int n); // O(n^2)
void SelectionSort(int arr[], int n); // O(n^2)
void InsertionSort(int arr[], int n); // O(n^2)
void HeapSort(int arr[], int n); // O(nlogn)
void MergeSort(int arr[], int left, int right);
#endif
