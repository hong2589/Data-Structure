#include "../include/Heap.h"
#include <stdio.h>
void Init(Heap* heap, PriorityComp _comp){
	heap->numOfData = 0;
	heap->comp = _comp;
}

int IsEmpty(Heap* heap){
	return (heap->numOfData == 0)? TRUE : FALSE;
}

void Insert(Heap* heap, HData data){
	int idx = heap->numOfData + 1;
	while (idx != 1){
		if (heap->comp(heap->heapArr[idx/2], data) >= 0){
			break;
		}
		heap->heapArr[idx] = heap->heapArr[idx/2];
		idx = idx / 2;
	}
	heap->heapArr[idx] = data;
	heap->numOfData += 1;
}

int GetPriorChildIdx(Heap* heap, int idx){
	int l_idx = 2 * idx;
	int r_idx = 2 * idx + 1;
	if (l_idx > heap->numOfData){
		return 0;
	}
	else if (l_idx == heap->numOfData){
		return l_idx;
	}
	else {
		if (heap->comp(heap->heapArr[l_idx], heap->heapArr[r_idx]) > 0){
			return l_idx;
		}
		else {
			return r_idx;
		}
	}
}

HData Delete(Heap* heap){
	HData delData = heap->heapArr[1];
	HData lastData = heap->heapArr[heap->numOfData];
	int parentIdx = 1;
	int childIdx;
	while ((childIdx = GetPriorChildIdx(heap, parentIdx)) != 0){
		if (heap->comp(lastData, heap->heapArr[childIdx]) >= 0){
			break;
		}
		heap->heapArr[parentIdx] = heap->heapArr[childIdx];
		parentIdx = childIdx;
	}
	heap->heapArr[parentIdx] = lastData;
	heap->numOfData -= 1;
	return delData;
}

void ShowInfo(Heap* heap){
	printf("Show all : ");
	for (int i = 1; i < heap->numOfData+1; i++){
		printf("%c ", heap->heapArr[i]);
	}
	printf("\n");
}