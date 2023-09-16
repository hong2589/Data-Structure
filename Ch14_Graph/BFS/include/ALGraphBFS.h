#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include "LinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual {
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;
} ALGraph;

typedef ALGraph Graph;

void GraphInit(Graph* pg, int nv);
void GraphDestroy(Graph* pg);
void AddEdge(Graph* pg, int fromV, int toV);
void ShowGraphEdgeInfo(Graph* pg);
int VisitVertex(Graph* pg, int visitV);
void BFShowGraphVertex(Graph* pg, int startV);

#endif