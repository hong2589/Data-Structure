#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include "LinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual {
	int numV;
	int numE;
	List* adjList;
} ALGraph;

typedef ALGraph Graph;

void GraphInit(Graph* pg, int nv);
void GraphDestroy(Graph* pg);
void AddEdge(Graph* pg, int fromV, int toV);
void ShowGraphEdgeInfo(Graph* pg);

#endif