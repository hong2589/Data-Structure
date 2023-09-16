#include "../include/ALGraph.h"
#include "../include/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int WhoIsPrecede(int d1, int d2){ return d2 - d1; }

void GraphInit(Graph* pg, int nv){
	pg->adjList = (List*)malloc(sizeof(List) * nv);

	pg->numV = nv;
	pg->numE = 0;

	for (int i = 0; i < nv; i++){
		LInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

void GraphDestroy(Graph* pg){
	if (pg->adjList != NULL){
		free(pg->adjList);
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