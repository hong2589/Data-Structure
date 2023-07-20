#include "../include/DBLinkedListDummy.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist){
	Node* headDummy = (Node*)malloc(sizeof(Node));
	Node* tailDummy = (Node*)malloc(sizeof(Node));

	headDummy->next = tailDummy;
	headDummy->prev = NULL;
	tailDummy->prev = headDummy;
	tailDummy->next = NULL;

	plist->head = headDummy;
	plist->tail = tailDummy;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	newNode->prev = plist->head;

	plist->head->next = newNode;
	plist->tail->prev = 
}
int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
int LPrev(List* plist, Data* pdata);
int LCount(List* plist);