#pragma once
#include "DataUtil.h"
typedef struct SList
{
	struct PList* neighbour;
	struct SList* next;
}AdjacentNode, *PAdjancentNode;
typedef struct PList
{
	Student* info;
	struct PList* next;
	struct SList* adjacencyList;

}Node, *PNode;

void insertGraphNode(Node** graphList, Student* info)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->info = info;
	node->next = *graphList;
	node->adjacencyList = NULL;
	*graphList = node;
}
Node* searchNode(Node* graphList, Student* info)
{
	while (graphList && graphList->info->reference.intRef != info->reference.intRef)
		graphList = graphList->next;
	return graphList;
}
void addEdge(Node* graphList, Student* source, Student* destination)
{
	/*Node* src = searchNode(graphList, source);
	if(src == NULL)
		insertGraphNode(graphList)
	Node* dst = searchNode(graphList, destination);
	insertNeighbour(&src->adjacencyList, dst);
	insertNeighbour(&dst->adjacencyList, src);*/
}