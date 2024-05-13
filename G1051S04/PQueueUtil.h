#pragma once
#include "DataUtil.h"

typedef struct PQueue
{
	Student** items;
	int size;
	int currentIndex;
} PriorityQueue, *PPriorityQueue;
#define PQueueInitialSize 7

void ReheapUp(PriorityQueue* pQueue, int childIndex)
{
	if (childIndex > 0)
	{
		int parentIndex = (childIndex - 1) / 2;
		if (pQueue->items[childIndex]->income > pQueue->items[parentIndex]->income)
		{
			Student* aux = pQueue->items[childIndex];
			pQueue->items[childIndex] = pQueue->items[parentIndex];
			pQueue->items[parentIndex] = aux;
			ReheapUp(pQueue, parentIndex);
		}
	}
}

void enque(PriorityQueue* pQueue, Student* stud)
{
	if (pQueue->items == NULL)
	{
		pQueue->items = (Student**)malloc(sizeof(Student*) * PQueueInitialSize);
		memset(pQueue->items, 0, sizeof(Student*) * PQueueInitialSize);
		pQueue->size = PQueueInitialSize;
	}
	if (pQueue->currentIndex < pQueue->size)
	{
		pQueue->items[pQueue->currentIndex] = stud;
		ReheapUp(pQueue, pQueue->currentIndex);
		pQueue->currentIndex++;
	}
}