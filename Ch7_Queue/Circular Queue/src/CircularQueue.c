#include "../include/CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

void Init(Queue* pq){
	pq->front = 0;
	pq->rear = 0;
}

int IsEmpty(Queue* pq){
	if (pq->front == pq->rear){
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int NextPosIdx(int pos){
	if (pos == QUE_LEN-1){
		return 0;
	}
	else {
		return pos + 1;
	}
}

void Enqueue(Queue* pq, Data data){
	if (NextPosIdx(pq->rear) == pq->front){ // if queue is full
		printf("Queue Memory Error!\n");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue* pq){
	if (IsEmpty(pq)){
		printf("Queue Memory Error!\n");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data Peek(Queue* pq){
	if (IsEmpty(pq)){
		printf("Queue Memory Error!\n");
		exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->front)];
}