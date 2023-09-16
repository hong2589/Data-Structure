#include <stdio.h>
#include "../include/ALGraph.h"
int main(){
	Graph graph;
	GraphInit(&graph, 5);

	// Add Edge
	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, A);

	ShowGraphEdgeInfo(&graph);
	GraphDestroy(&graph);
	return 0;
}