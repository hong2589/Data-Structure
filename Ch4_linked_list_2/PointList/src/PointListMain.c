#include <stdio.h>
#include <stdlib.h>
#include "../include/Point.h"
#include "../include/LinkedList.h"

int CompPos(Point* p1, Point* p2){
	if (p1->xpos < p2->xpos) return 0;
	else if (p1->xpos > p2->xpos) return 1;
	else return (p1->ypos > p2->ypos)? 1 : 0;
}

int main(){
	List list;
	Point compPos;
	Point* ppos;

	LInit(&list);
	SetSortRule(&list, CompPos);

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