#include "../include/Point.h"
#include <stdio.h>
void SetPointPos(Point* p, int xpos, int ypos){
	p->xpos = xpos;
	p->ypos = ypos;	
}

void ShowPointPos(Point* p){
	printf("[%d, %d]\n", p->xpos, p->ypos);
}

int PointComp(Point* p1, Point* p2){
	if (p1->xpos == p2->xpos){
		return (p1->ypos == p2->ypos)? 0 : 1;
	}
	else {
		return (p1->ypos == p2->ypos)? 2 : -1;
	}
}