#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#include "LinkedList.h"

#define TRUE 1
#define FALSE 0
typedef int Data;

// typedef struct _qnode {
// 	Data data;
// 	struct _qnode* next;
// } Node;

typedef struct _lQueue {
	Node* front;
	Node* rear;
} LQueue;

typedef LQueue Queue;

void Init(Queue* pq);
int IsEmpty(Queue* pq);
void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data Peek(Queue* pq);

#endif