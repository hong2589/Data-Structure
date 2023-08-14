#include "../include/ListBaseQueue.h"
#include <stdio.h>
#include <stdlib.h>

void Init(Queue* pq){
	pq->front = NULL;
	pq->rear = NULL;
}

int IsEmpty(Queue* pq){
	if (pq->front == NULL){
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void Enqueue(Queue* pq, Data data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if (IsEmpty(pq)){
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue* pq){
	Node* rnode;
	Data rdata;
	if (IsEmpty(pq)){
		printf("Queue Memory Error!\n");
		exit(-1);
	}
	rnode = pq->front;
	rdata = pq->front->data;
	pq->front = pq->front->next;
	free(rnode);
	return rdata;
}

Data Peek(Queue* pq){
	if (IsEmpty(pq)){
		printf("Queue Memory Error!\n");
		exit(-1);
	}
	return pq->front->data;
}