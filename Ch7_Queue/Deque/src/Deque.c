#include "../include/Deque.h"
#include <stdio.h>
#include <stdlib.h>
void Init(Deque* deq){
	deq->head = NULL;
	deq->tail = NULL;
}
int IsEmpty(Deque* deq){
	return (deq->head == NULL)? TRUE : FALSE;
}
void AddFirst(Deque* deq, Data data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = deq->head;
	newNode->prev = NULL;
	if (IsEmpty(deq)){
		deq->head = newNode;
		deq->tail = newNode;
	}
	else {
		deq->head->prev = newNode;
		deq->head = newNode;
	}
}
void AddLast(Deque* deq, Data data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = deq->tail;
	newNode->next = NULL;
	if (IsEmpty(deq)){
		deq->head = newNode;
		deq->tail = newNode;
	}
	else {
		deq->tail->next = newNode;
		deq->tail = newNode;
	}
}
Data RemoveFirst(Deque* deq){
	Node* delNode;
	Data rData;
	if (IsEmpty(deq)){
		printf("Deque Memory Error!\n");
		exit(-1);
	}
	delNode = deq->head;
	rData = deq->head->data;
	deq->head = deq->head->next;
	free(delNode);

	if (deq->head == NULL){
		deq->tail = NULL;
	}
	else {
		deq->head->prev = NULL;
	}
	return rData;
}
Data RemoveLast(Deque* deq){
	Node* delNode = deq->tail;
	Data rData;
	if (IsEmpty(deq)){
		printf("Deque Memory Error!\n");
		exit(-1);
	}
	rData = delNode->data;
	deq->tail = deq->tail->prev;
	free(delNode);
	if (deq->tail == NULL){
		deq->head = NULL;
	}
	else {
		deq->tail->next = NULL;
	}
	return rData;
}
Data GetFirst(Deque* deq){
	if (IsEmpty(deq)){
		printf("Deque Memory Error!\n");
		exit(-1);
	}
	return deq->head->data;
}
Data GetLast(Deque* deq){
	if (IsEmpty(deq)){
		printf("Deque Memory Error!\n");
		exit(-1);
	}
	return deq->tail->data;
}