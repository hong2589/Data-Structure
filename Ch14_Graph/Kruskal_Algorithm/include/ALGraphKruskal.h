#ifndef __AL_GRAPH_KRUSKAL_H__
#define __AL_GRAPH_KRUSKAL_H__

#include "LinkedList.h"
#include "Heap.h"
#include "ALEdge.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual {
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;
	Heap heap;
} ALGraph;

typedef ALGraph Graph;

void GraphInit(Graph* pg, int nv);
void GraphDestroy(Graph* pg);
void AddEdge(Graph* pg, int fromV, int toV, int weight);
void ShowGraphEdgeInfo(Graph* pg);
void DFShowGraphVertex(Graph* pg, int startV);
void ConKruskalMST(Graph* pg);
void ShowGraphEdgeWeightInfo(Graph* pg);

#endif