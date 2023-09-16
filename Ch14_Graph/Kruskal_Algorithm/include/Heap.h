#ifndef __HEAP_H__
#define __HEAP_H__
#include <stdio.h>
#include "ALEdge.h"

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef Edge HData;
typedef int (*PriorityComp)(HData, HData);

typedef struct _heap {
	HData heapArr[HEAP_LEN];
	int numOfData;
	PriorityComp comp;
} Heap;

void Init(Heap* heap, PriorityComp _comp);
int HIsEmpty(Heap* heap);
void Insert(Heap* heap, HData data);
HData Delete(Heap* heap);
void ShowInfo(Heap* heap);

#endif