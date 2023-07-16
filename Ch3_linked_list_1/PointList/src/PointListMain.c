#include <stdio.h>
#include <stdlib.h>
#include "../include/Point.h"
#include "../include/ArrayList.h"

int main(){
	List list;
	Point compPos;
	Point* ppos;

	ListInit(&list);

	// store 4 data
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	printf("# of Data : %d\n", list.numOfData);

	if (LFirst(&list, &ppos)){
		ShowPointPos(ppos);
		while (LNext(&list, &ppos)){
			ShowPointPos(ppos);
		}
	}
	printf("\n");


	// Remove xpos = 2 data
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos)){
		if (PointComp(ppos, &compPos) == 1){
			ppos = LRemove(&list);
			free(ppos);
		}
		while(LNext(&list, &ppos)){
			if (PointComp(ppos, &compPos) == 1){
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	printf("current # of data : %d\n", list.numOfData);
	if (LFirst(&list, &ppos)){
		ShowPointPos(ppos);
		while (LNext(&list, &ppos)){
			ShowPointPos(ppos);
		}
	}
	return 0;
}