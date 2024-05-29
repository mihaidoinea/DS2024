#pragma once
#include "DataUtil.h"
typedef struct NodeN
{
	struct NodeG* neighbour;
	struct NodeN* next;
}Neighbour, *PNeighbour;
typedef struct NodeG
{
	Student* info;
	struct NodeG* next;
	struct NodeN* neighbours;
}Graph, *PGraph;

Graph* createVertex(Student* info)
{
	Graph* node = (Graph*)malloc(sizeof(Graph));
	node->info = info;
	node->neighbours = NULL;
	node->next = NULL;
	return node;
}
Neighbour* createNeighbour(Graph* info)
{
	Neighbour* node = (Neighbour*)malloc(sizeof(Neighbour));
	node->neighbour = info;
	node->next = NULL;
	return node;
}
Graph* searchVertex(Graph* graph, unsigned short key)
{
	while (graph != NULL && graph->info->reference.intRef != key)
		graph = graph->next;
	return graph;
}
Neighbour* searchNeighbour(Neighbour* list, unsigned short key)
{
	while (list != NULL && list->neighbour->info->reference.intRef != key)
		list = list->next;
	return list;
}
void addEdge(Graph** graph, Student* src, Student* dst)
{
	//inserare noduri in cazul in care nu exista
	Graph* sNode = searchVertex(*graph, src->reference.intRef);
	if (sNode == NULL)
	{
		sNode = createVertex(src);
		sNode->next = *graph;
		*graph = sNode;
	}
	Graph* dNode = searchVertex(*graph, dst->reference.intRef);
	if (dNode == NULL)
	{
		dNode = createVertex(dst);
		dNode->next = *graph;
		*graph = dNode;
	}
	if (searchNeighbour(sNode->neighbours, dst->reference.intRef) == NULL)
	{
		Neighbour* neighbour = createNeighbour(dNode);
		neighbour->next = sNode->neighbours;
		sNode->neighbours = neighbour;
	}
	if (searchNeighbour(dNode->neighbours, src->reference.intRef) == NULL)
	{
		Neighbour* neighbour = createNeighbour(sNode);
		neighbour->next = dNode->neighbours;
		dNode->neighbours = neighbour;
	}
}
void printGraph(Graph* graph)
{
	while (graph != NULL)
	{
		printf("Student: %s\n", graph->info->name);
		Neighbour* node = graph->neighbours;
		printf("Neighbours: \n");
		while (node != NULL)
		{
			printf("\t%s\n", node->neighbour->info->name);
			node = node->next;
		}
		printf("\n");
		graph = graph->next;
	}
}
