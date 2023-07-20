#include "../include/DBLinkedList.h"
#include <stdio.h>
int main(){
	List list;
	int data;

	// Insert data
	ListInit(&list);
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);

	// Print all the data
	if (LFirst(&list, &data)){
		printf("%d ", data);
		
		// shift to right
		while(LNext(&list, &data)) printf("%d ", data);

		// shift to left
		while(LPrev(&list, &data)) printf("%d ", data);

		printf("\n\n");
	}

	return 0;
}