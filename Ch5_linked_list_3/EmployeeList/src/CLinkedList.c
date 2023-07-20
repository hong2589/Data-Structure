#include "../include/CLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist){
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->tail == NULL){
		plist->tail = newNode;
		plist->tail->next = plist->tail;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	plist->numOfData += 1;
}

void LInsertFront(List* plist, Data data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->tail == NULL){
		plist->tail = newNode;
		plist->tail->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	plist->numOfData += 1;
}

int LFirst(List* plist, Data* pdata){
	if (plist->tail == NULL) return FALSE;
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata){
	if (plist->tail == NULL) return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist){
	Node* rmNode = plist->cur;
	Data rmData = rmNode->data;

	if (rmNode == plist->tail){
		if (plist->tail->next == plist->tail){
			plist->tail = NULL;
		}
		else {
			plist->tail = plist->before;
		}
	}
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(rmNode);
	plist->numOfData -= 1;
	return rmData;
}

int LCount(List* plist){
	return plist->numOfData;
}