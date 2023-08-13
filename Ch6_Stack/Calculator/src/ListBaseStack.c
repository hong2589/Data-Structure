#include "../include/ListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>

void Init(Stack* pstack){
	pstack->head = NULL;
}

int IsEmpty(Stack* pstack){
	if (pstack->head == NULL){
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void Push(Stack* pstack, Data data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data Pop(Stack* pstack){
	Data rdata;
	Node* rnode;
	
	if (IsEmpty(pstack)){
		printf("Stack Memory Error!\n");
		exit(-1);
	}
	rdata = pstack->head->data;
	rnode = pstack->head;
	pstack->head = rnode->next;
	free(rnode);
	return rdata;
}

Data Peek(Stack* pstack){
	if (IsEmpty(pstack)){
		printf("Stack Memory Error!\n");
		exit(-1);
	}
	return pstack->head->data;
}


