#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack{
	Data stackArr[STACK_LEN];
	int topIdx;
} ArrayStack;

typedef ArrayStack Stack;

// Functions
void Init(Stack* pstack);
int IsEmpty(Stack* pstack);
void Push(Stack* pstack, Data data);
Data Pop(Stack* pstack);
Data Peek(Stack* pstack);

#endif