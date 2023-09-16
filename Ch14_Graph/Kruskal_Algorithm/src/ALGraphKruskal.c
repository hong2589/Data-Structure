#include "../include/ALGraphKruskal.h"
#include "../include/LinkedList.h"
#include "../include/ArrayBaseStack.h"
#include "../include/ALEdge.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int WhoIsPrecede(int d1, int d2){ return d2 - d1; }
int WeightComp(Edge e1, Edge e2){ return e1.weight - e2.weight; }

void GraphInit(Graph* pg, int nv){
	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->visitInfo = (int*)malloc(sizeof(int) * nv);

	pg->numV = nv;
	pg->numE = 0;
	memset(pg->visitInfo, 0, sizeof(int) * nv);
	Init(&(pg->heap), WeightComp);

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

void AddEdge(Graph* pg, int fromV, int toV, int weight){
	Edge edge = {fromV, toV, weight};
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	Insert(&(pg->heap), edge); // save weight info to heap(priority queue)
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

void ShowGraphEdgeWeightInfo(Graph* pg){
	Heap cpHeap = pg->heap;
	Edge edge;

	while (!HIsEmpty(&cpHeap)){
		edge = Delete(&cpHeap);
		printf("(%c - %c), w = %d\n", edge.v1+'A', edge.v2+'A', edge.weight);
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

	SInit(&stack);
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
			if (SIsEmpty(&stack)){
				break;
			}
			else {
				visitV = Pop(&stack);
			}
		}
	}
	memset(pg->visitInfo, 0, sizeof(int)*(pg->numV));
}

void RemoveEdge(Graph* pg, Edge* pe){
	int vertex;
	// one direction
	if (LFirst(&(pg->adjList[pe->v1]), &vertex)){
		if (vertex == pe->v2){
			LRemove(&(pg->adjList[pe->v1]));
		}
		else {
			while (LNext(&(pg->adjList[pe->v1]), &vertex)){
				if (vertex == pe->v2){
					LRemove(&(pg->adjList[pe->v1]));
				}
			}
		}
	}
	// opposite direction
	if (LFirst(&(pg->adjList[pe->v2]), &vertex)){
		if (vertex == pe->v1){
			LRemove(&(pg->adjList[pe->v2]));
		}
		else {
			while (LNext(&(pg->adjList[pe->v2]), &vertex)){
				if (vertex == pe->v1){
					LRemove(&(pg->adjList[pe->v2]));
				}
			}
		}
	}
	pg->numE -= 1;
}

int IsConnected(Graph* pg, Edge* pe){
	Stack stack;
	int visitV = pe->v1;
	int nextV;
	printf("Inside IsConnected\n");
	ShowGraphEdgeWeightInfo(pg);

	SInit(&stack);
	VisitVertex(pg, visitV);
	while (LFirst(&(pg->adjList[visitV]), &nextV)){
		int visitFlag = FALSE;
		// pe->v2 founded
		if (nextV == pe->v2){
			memset(pg->visitInfo, 0, sizeof(int) * (pg->numV));
			return TRUE;
		}

		if (VisitVertex(pg, nextV)){
			Push(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {
			while (LNext(&(pg->adjList[visitV]), &nextV)){
				if (nextV == pe->v2){
					memset(pg->visitInfo, 0, sizeof(int) * (pg->numV));
					return TRUE;
				}
				if (VisitVertex(pg, nextV)){
					Push(&stack, visitV);
					visitFlag = TRUE;
					visitV = nextV;
					break;
				}
			}
		}

		if (!visitFlag){
			if (SIsEmpty(&stack)){
				break;
			}
			else {
				visitV = Pop(&stack);
			}
		}
	}
	memset(pg->visitInfo, 0, sizeof(int) * (pg->numV));
	return FALSE;
}

void RecoverEdge(Graph* pg, Edge* pe){
	LInsert(&(pg->adjList[pe->v1]), pe->v2);
	LInsert(&(pg->adjList[pe->v2]), pe->v1);
	pg->numE += 1;
}

void ConKruskalMST(Graph* pg){
	Edge recvEdge[20];
	Edge edge;
	int recvNum = 0;

	while (pg->numE+1 > pg->numV){
		edge = Delete(&(pg->heap));
		printf("RemoveEdge : (%c - %c)\n", edge.v1 + 'A', edge.v2 + 'A');
		RemoveEdge(pg, &edge);
		if (!IsConnected(pg, &edge)){
			RecoverEdge(pg, &edge);
			recvEdge[recvNum++] = edge;
		}
		// ShowGraphEdgeWeightInfo(pg);
	}

	for (int i = 0; i < recvNum; i++){
		Insert(&(pg->heap), recvEdge[i]);
	}
}

