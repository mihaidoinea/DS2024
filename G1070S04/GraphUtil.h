#pragma once
#include "DataUtil.h"
typedef struct SList
{
	struct PList* mainVertex;
	struct SList* nextNeighbour;
}AdjacentNode, *PAdjancentNode;

typedef struct PList
{
	Student* info;
	struct PList* nextVertex;
	struct SList* adjacencyList;

}Vertex, *PVertex;

typedef struct MatNode
{
	Vertex* src;
	AdjacentNode* dst;
}MatNode;

Vertex* searchNode(Vertex* graphList, Student* info)
{
	while (graphList && graphList->info->reference.intRef != info->reference.intRef)
		graphList = graphList->nextVertex;
	return graphList;
}
Vertex* createVertex(Student* info)
{
	Vertex* node = (Vertex*)malloc(sizeof(Vertex));
	node->adjacencyList = NULL;
	node->nextVertex = NULL;
	node->info = info;
	return node;
}

void insertNeighbour(AdjacentNode** neighbours, Vertex* mainVertex)
{
	AdjacentNode* node = (AdjacentNode*)malloc(sizeof(AdjacentNode));
	node->mainVertex = mainVertex;
	node->nextNeighbour = *neighbours;
	*neighbours = node;
}
void addEdge(Vertex** graphList, Student* source, Student* destination)
{
	Vertex* src = searchNode(*graphList, source);
	if (src == NULL)
	{
		//add a new vertex to the graph
		src = createVertex(source);
		src->nextVertex = *graphList;
		*graphList = src;
	}
	Vertex* dst = searchNode(*graphList, destination);
	if (dst == NULL)
	{
		dst = createVertex(destination);
		dst->nextVertex = *graphList;
		*graphList = dst;
	}
	insertNeighbour(&src->adjacencyList, dst);
	insertNeighbour(&dst->adjacencyList, src);
}
void displayGraph(Vertex* graph)
{
	while (graph)
	{
		printf("Vertex: %s, List of neighbours:\n", graph->info->name);
		AdjacentNode* list = graph->adjacencyList;
		while (list)
		{
			printf("\t%s\n", list->mainVertex->info->name);
			list = list->nextNeighbour;
		}
		graph = graph->nextVertex;
	}
}
void convertListToMat(Vertex* graph, MatNode** matrix)
{
	int i=0, j=0;
	while (graph)
	{
		AdjacentNode* list = graph->adjacencyList;
		while (list)
		{
			MatNode node = { .src = graph, .dst = list };
			matrix[i][j] = node;
			list = list->nextNeighbour;
		}
		graph = graph->nextVertex;
	}
}