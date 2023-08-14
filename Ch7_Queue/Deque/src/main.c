#include "../include/Deque.h"
#include <stdio.h>
int main(void){
	Deque deq;
	Init(&deq);

	AddFirst(&deq, 3);
	AddFirst(&deq, 2);
	AddFirst(&deq, 1);
	AddLast(&deq, 4);
	AddLast(&deq, 5);
	AddLast(&deq, 6);

	while (!IsEmpty(&deq)){
		printf("%d ", RemoveFirst(&deq));
	}
	printf("\n");

	return 0;
}