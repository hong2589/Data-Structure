#include "../include/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void LInit(List* list){
	list->numOfData = 0;
	list->head = (Node*)malloc(sizeof(Node)); // DMY
	list->cur = NULL;
	list->before = NULL;
	list->comp = NULL;
}

void LInsert(List* list, LData data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list->head->next;
	list->head->next = newNode;
	list->numOfData += 1;
}

int LFirst(List* list, LData* pdata){
	if (list->head->next == NULL){
		return FALSE;
	}
	list->before = list->head;
	list->cur = list->head->next;
	*pdata = list->cur->data;
	return TRUE;
}

int LNext(List* list, LData* pdata){
	if (list->cur->next == NULL) return FALSE;
	list->cur = list->cur->next;
	list->before = list->before->next;
	*pdata = list->cur->data;
	return TRUE;
}

LData LRemove(List* list){
	Node* rmNode = list->cur;
	LData rmData = list->cur->data;

	list->before->next = rmNode->next;
	list->cur = rmNode->next;
	free(rmNode);
	list->numOfData -= 1;
	return rmData;
}

int LCount(List* list){
	return list->numOfData;
}

void SetSortRule(List* list, LComp comp){
	list->comp = comp;
}