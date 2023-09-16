#include "../include/ALGraphDFS.h"
#include "../include/LinkedList.h"
#include "../include/ArrayBaseStack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int WhoIsPrecede(int d1, int d2){ return d2 - d1; }

void GraphInit(Graph* pg, int nv){
	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->visitInfo = (int*)malloc(sizeof(int) * nv);

	pg->numV = nv;
	pg->numE = 0;
	memset(pg->visitInfo, 0, sizeof(int) * nv);

	for (int i = 0; i < nv; i++){
		LInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

void GraphDestroy(Graph* pg){
	if (pg->adjList != NULL){
		free(pg->adjList);
	}
	if (pg->visitInfo != NULL){
		free(pg->visitInfo);
	}
}

void AddEdge(Graph* pg, int fromV, int toV){
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(Graph* pg){
	int vx;
	for (int i = 0; i < pg->numV; i++){
		printf("Vertices connected to %c : ", i+'A');
		if (LFirst(&(pg->adjList[i]), &vx)){
			printf("%c ", vx+'A');
			while (LNext(&(pg->adjList[i]), &vx)){
				printf("%c ", vx+'A');
			}
		}
		printf("\n");
	}
}

int VisitVertex(Graph* pg, int visitV){
	if (pg->visitInfo[visitV] == 0){
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 'A');
		return TRUE;
	}
	else return FALSE;
}

void DFShowGraphVertex(Graph* pg, int startV){
	Stack stack;
	int visitV = startV;
	int nextV;

	Init(&stack);
	VisitVertex(pg, visitV);
	while (LFirst(&(pg->adjList[visitV]), &nextV)){
		int visitFlag = FALSE;
		if (VisitVertex(pg, nextV)){
			visitFlag = TRUE;
			Push(&stack, visitV);
			visitV = nextV;
		}
		else {
			while (LNext(&(pg->adjList[visitV]), &nextV)){
				if (VisitVertex(pg, nextV)){
					visitFlag = TRUE;
					Push(&stack, visitV);
					visitV = nextV;
					break;
				}
			}
		}

		if (!visitFlag){
			if (IsEmpty(&stack)){
				break;
			}
			else {
				visitV = Pop(&stack);
			}
		}
	}
	memset(pg->visitInfo, 0, sizeof(int)*(pg->numV));
}