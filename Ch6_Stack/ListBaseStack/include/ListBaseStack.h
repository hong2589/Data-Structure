#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE 1
#define FALSE 0
typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
} Node;

typedef struct _listStack {
	Node* head;
} ListStack;

typedef ListStack Stack;

void Init(Stack* pstack);
int IsEmpty(Stack* pstack);
void Push(Stack* pstack, Data data);
Data Pop(Stack* pstack);
Data Peek(Stack* pstack);

#endif