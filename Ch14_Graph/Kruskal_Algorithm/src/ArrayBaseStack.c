#include "ArrayBaseStack.h"
#include <stdio.h>
#include <stdlib.h>

void SInit(Stack* pstack){
	pstack->topIdx = -1; // -1 means empty state
}

int SIsEmpty(Stack* pstack){
	return (pstack->topIdx==-1)? TRUE : FALSE;
}

void Push(Stack* pstack, Data data){
	pstack->topIdx += 1;
	pstack->stackArr[pstack->topIdx] = data;
}

Data Pop(Stack* pstack){
	Data rdata;
	if (SIsEmpty(pstack)){
		printf("No data in the stack...\n");
		exit(-1);
	}
	rdata = pstack->stackArr[pstack->topIdx];
	pstack->topIdx -= 1;
	return rdata;
}

Data Peek(Stack* pstack){
	if (SIsEmpty(pstack)){
		printf("No data in the stack...\n");
		exit(-1);
	}
	return pstack->stackArr[pstack->topIdx];
}


