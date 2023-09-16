#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;
typedef int (*LComp)(LData, LData);

typedef struct _node {
	LData data;
	struct _node* next;
} Node;

typedef struct _linkedList {
	int numOfData;
	Node* head; // head = DMY
	Node* cur;
	Node* before;
	LComp comp;
} LinkedList;

typedef LinkedList List;

void LInit(List* list);
void LInsert(List* list, LData data);
int LFirst(List* list, LData* pdata);
int LNext(List* list, LData* pdata);
LData LRemove(List* list);
int LCount(List* list);
void SetSortRule(List* list, LComp comp);

#endif