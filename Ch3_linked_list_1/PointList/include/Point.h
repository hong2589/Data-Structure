#ifndef __POINT_H__
#define __POINT_H__

typedef struct
{
	int xpos;
	int ypos;
} Point;

void SetPointPos(Point* p, int xpos, int ypos);
void ShowPointPos(Point* p);
int PointComp(Point* p1, Point* p2);


#endif
