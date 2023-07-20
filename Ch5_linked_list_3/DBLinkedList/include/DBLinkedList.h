#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define FALSE 0
#define TRUE 1
typedef int Data;

// Node
typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
} Node;

// Doubly-Linked-List
typedef struct _DLL {
	Node* cur;
	Node* head;
	int numOfData;
} DBList;

typedef DBList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);
int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
int LPrev(List* plist, Data* pdata);
int LCount(List* plist);
#endif