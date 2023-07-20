#include "../include/DBLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist){
	plist->numOfData = 0;
	plist->head = NULL;
	plist->cur = NULL;
}

void LInsert(List* plist, Data data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->head == NULL){
		plist->head = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else {
		plist->head->prev = newNode;
		newNode->next = plist->head;
		plist->head = newNode;
	}
	plist->numOfData += 1;
}

int LFirst(List* plist, Data* pdata){
	if (plist->head == NULL) return FALSE;
	plist->cur = plist->head;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata){
	if (plist->cur->next == NULL) return FALSE;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LPrev(List* plist, Data* pdata){
	if (plist->cur->prev == NULL) return FALSE;
	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
}

int LCount(List* plist){
	return plist->numOfData;
}