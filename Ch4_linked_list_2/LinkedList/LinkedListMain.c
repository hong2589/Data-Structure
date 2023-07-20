#include "LinkedList.h"
#include <stdio.h>
int WhoIsPrecede(int d1, int d2){
	if (d1 < d2) return 0;
	else return 1;
}

int main(){
	List list;
	int data;
	LInit(&list);
	SetSortRule(&list, WhoIsPrecede);

	// Input data
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	printf("# of data : %d\n", LCount(&list));

	// Show all
	if (LFirst(&list, &data)){
		printf("%d ", data);
		while(LNext(&list, &data)){
			printf("%d ", data);
		}
	}
	printf("\n\n");

	// Remove data 22
	if (LFirst(&list, &data)){
		if (data == 22){
			LRemove(&list);
		}
		while (LNext(&list, &data)){
			if (data == 22){
				LRemove(&list);
			}
		}
	}

	// print all
	printf("# of data : %d\n", LCount(&list));
	if (LFirst(&list, &data)){
		printf("%d ", data);
		while (LNext(&list, &data)){
			printf("%d ", data);
		}
	}
	printf("\n\n");
	return 0;
}