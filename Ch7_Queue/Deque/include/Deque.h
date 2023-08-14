#ifndef __DEQUE_H__
#define __DEQUE_H__

// Double-Ended Queue

#define TRUE 1
#define FALSE 0
typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
} Node;

typedef struct _deque {
	Node* head;
	Node* tail;
} Deque;

void Init(Deque* deq);
int IsEmpty(Deque* deq);
void AddFirst(Deque* deq, Data data);
void AddLast(Deque* deq, Data data);
Data RemoveFirst(Deque* deq);
Data RemoveLast(Deque* deq);
Data GetFirst(Deque* deq);
Data GetLast(Deque* deq);

#endif