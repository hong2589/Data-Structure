#ifndef _CLINKED_LIST_H__
#define _CLINKED_LIST_H__

#define FALSE 0
#define TRUE 1
typedef int Data;

// Node
typedef struct _node {
	Data data;
	struct _node* next;
} Node;

// Circular-Linked-List
typedef struct _CLL {
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} CList;

typedef CList List;

// CLL Functions
void ListInit(List* plist);
void LInsert(List* plist, Data data); // insert data to tail
void LInsertFront(List* plist, Data data); // insert data to head
int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
Data LRemove(List* plist);
int LCount(List* plist);

#endif