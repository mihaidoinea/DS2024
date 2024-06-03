#pragma once
#include "DataUtil.h"
typedef struct ANode
{
	struct GNode* mainVertex;
	struct ANode* nextNeighbour;
}Neighbour, * PNeighbour;
typedef struct GNode
{
	Student* info;
	struct GNode* nextVertex;
	struct ANode* neighbours;
}Vertex, *PVertex;

void insertNeighbour(Vertex* sNode, Vertex* dNode)
{
	Neighbour* neighbour = (Neighbour*)malloc(sizeof(Neighbour));
	neighbour->mainVertex = dNode;
	neighbour->nextNeighbour = sNode->neighbours;
	sNode->neighbours = neighbour;
}
Vertex* createVertex(Student* info)
{
	Vertex* node = (Vertex*)malloc(sizeof(Vertex));
	node->info = info;
	node->neighbours = NULL;
	node->nextVertex = NULL;
	return node;
}
Vertex* searchVertex(Vertex* list, unsigned short key)
{
	while (list && list->info->reference.intRef != key)
	{
		list = list->nextVertex;
	}
	return list;
}
void addEdge(Vertex** graph, Student* src, Student* dst)
{
	Vertex* sVertex = searchVertex(*graph, src->reference.intRef);
	if (sVertex == NULL)
	{
		sVertex = createVertex(src);
		sVertex->nextVertex = *graph;
		*graph = sVertex;
	}
	Vertex* dVertex = searchVertex(*graph, dst->reference.intRef);
	if (dVertex == NULL)
	{
		dVertex = createVertex(dst);
		dVertex->nextVertex = *graph;
		*graph = dVertex;
	}
	insertNeighbour(sVertex, dVertex);
	insertNeighbour(dVertex, sVertex);
}

void displayGraph(Vertex* graph)
{
	while (graph)
	{
		printf("Vertex: %s\n", graph->info->name);
		Neighbour* list = graph->neighbours;
		printf("Connections:\n");
		while (list)
		{
			printf("\t%s\n", list->mainVertex->info->name);
			list = list->nextNeighbour;
		}
		graph = graph->nextVertex;
	}
}