#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void LInit(List* plist){
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data){
	// There is no sorting rule -> just insert to head
	if (plist->comp == NULL){
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;

		newNode->next = plist->head->next;
		plist->head->next = newNode;

		plist->numOfData += 1;
	}
	// There is sorting rule -> insert according to sorting rule
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		
		Node* pred = plist->head; // dummy
		while (pred->next != NULL && plist->comp(pred, pred->next) != 0){
			pred = pred->next;
		}
		newNode->next = pred->next;
		pred->next = newNode;

		plist->numOfData += 1;
	}
}

int LFirst(List* plist, LData* pdata){
	if (plist->head->next == NULL){
		return FALSE;
	}

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data; 
	return TRUE;
}

int LNext(List* plist, LData* pdata){
	if (plist->cur->next == NULL){
		return FALSE;
	}
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist){
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

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