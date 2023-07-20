#include "CLinkedList.h"
#include <stdio.h>
int main(){
	List list;
	Data data;
	int nodeNum;
	ListInit(&list);

	// 1. Input 5 data to list
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	// 2. Print all the data of the list by 3 times
	if (LFirst(&list, &data)){
		printf("%d ", data);
		for (int i = 0; i < LCount(&list)*3 - 1; i++){
			if (LNext(&list, &data)){
				printf("%d ", data);
			}
		}
	}
	printf("\n\n");

	// 3. Delete multiples of 2
	nodeNum = LCount(&list);
	if (LFirst(&list, &data)){
		if (data % 2 == 0){
			LRemove(&list);
		}
		for (int i = 0; i < nodeNum-1; i++){
			LNext(&list, &data);
			if (data % 2 == 0){
				LRemove(&list);
			}
		}
	}

	// 4. Print all the data of list
	if (LFirst(&list, &data)){
		printf("%d ", data);
		for (int i = 0; i < LCount(&list)-1; i++){
			if (LNext(&list, &data)){
				printf("%d ", data);
			}
		}
	}
	printf("\n");
	return 0;
}