#include "../include/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void LInit(List* plist){
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data){
	if (plist->comp == NULL){
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = plist->head->next;
		plist->head = newNode;
		plist->numOfData += 1;
	}
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		Node* pred = plist->head;
		newNode->data = data;
		while (pred->next != NULL && plist->comp(newNode->data, pred->next->data) != 0){
			pred = pred->next;
		}
		newNode->next = pred->next;
		pred->next = newNode;
		plist->numOfData += 1;
	}
}

int LFirst(List* plist, LData* pdata){
	if (plist->head->next == NULL) return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata){
	if (plist->cur->next == NULL) return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist){
	LData rdata = plist->cur->data;
	Node* rpos = plist->cur;

	plist->cur = plist->before;
	plist->cur->next = rpos->next;

	free(rpos);
	plist->numOfData -= 1;
	return rdata;
}

int LCount(List* plist){
	return plist->numOfData;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)){
	plist->comp = comp;
}