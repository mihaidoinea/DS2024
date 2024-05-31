#pragma once
#include "DataUtil.h"
typedef struct SList
{
	struct PList* mainVertex;
	struct SList* nextNeighbour;
}AdjacentNode, * PAdjancentNode;

typedef struct PList
{
	Student* info;
	struct PList* nextVertex;
	struct SList* adjacencyList;

}Node, *PNode;

typedef struct MatNode
{
	Node* src;
	AdjacentNode* dst;
}MatNode;

Node* createVertex(Student* info)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->info = info;
	node->nextVertex = NULL;
	node->adjacencyList = NULL;
	return node;
}

Node* searchNode(Node* graphList, Student* info)
{
	while (graphList && graphList->info->reference.intRef != info->reference.intRef)
		graphList = graphList->nextVertex;
	return graphList;
}
void insertNeighbour(AdjacentNode** neighbours, Node* mainVertex)
{
	AdjacentNode* node = (AdjacentNode*)malloc(sizeof(AdjacentNode));
	node->mainVertex = mainVertex;
	node->nextNeighbour = (*neighbours);
	*neighbours = node;
}
void addEdge(Node** graphList, Student* source, Student* destination)
{
	Node* src = searchNode(*graphList, source);
	if (src == NULL)
	{
		src = createVertex(source);
		src->nextVertex = *graphList;
		*graphList = src;
	}
	Node* dst = searchNode(*graphList, destination);
	if (dst == NULL)
	{
		dst = createVertex(destination);
		dst->nextVertex = *graphList;
		*graphList = dst;
	}
	insertNeighbour(&src->adjacencyList, dst);
	insertNeighbour(&dst->adjacencyList, src);
}

void displayGraph(Node* graph)
{
	while (graph)
	{
		printf("Vertex: %s\n", graph->info->name);
		AdjacentNode* list = graph->adjacencyList;
		printf("\tNeighbours:\n");
		while (list)
		{
			printf("\t\t%s\n", list->mainVertex->info->name);
			MatNode el = { .src = graph, .dst = list };
			list = list->nextNeighbour;
		}
		printf("-------------------------\n");
		graph = graph->nextVertex;
	}
}