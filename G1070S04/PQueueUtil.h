#pragma once
#include "DataUtil.h"
#define PQUEUE_SIZE 7
typedef struct PQueue
{
	Student** items;
	int size;
	int currentIndex;
}PriorityQueue;

void ReheapUp(Student** items, int currentIndex)
{
	if (currentIndex > 0)
	{
		int parentIndex = (currentIndex - 1) / 2;
		if (items[parentIndex]->income <
			items[currentIndex]->income)
		{
			Student* aux = items[parentIndex];
			items[parentIndex] = items[currentIndex];
			items[currentIndex] = aux;
			ReheapUp(items, parentIndex);
		}
	}
}

void enqueue(struct PQueue* pQueue, Student* info)
{
	if ((*pQueue).items == NULL)
	{
		(*pQueue).items = (Student**)malloc(sizeof(Student*) * PQUEUE_SIZE);
		memset((*pQueue).items, 0, sizeof(Student*) * PQUEUE_SIZE);
		(*pQueue).size = PQUEUE_SIZE;
	}
	if ((*pQueue).size > (*pQueue).currentIndex)
	{
		(*pQueue).items[(*pQueue).currentIndex] = info;
		ReheapUp((*pQueue).items, (*pQueue).currentIndex);
		(*pQueue).currentIndex++;
	}
}

void ReheapDown(PriorityQueue* pQueue, int parentIndex)
{
	int lChildIndex = 2 * parentIndex + 1;
	int rChildIndex = 2 * parentIndex + 2;
	int maxIndex = parentIndex;
	if (lChildIndex < pQueue->currentIndex)
	{
		if (pQueue->items[lChildIndex]->income > pQueue->items[maxIndex]->income)
			maxIndex = lChildIndex;
		if (rChildIndex < pQueue->currentIndex &&
			pQueue->items[rChildIndex]->income > pQueue->items[maxIndex]->income)
			maxIndex = rChildIndex;
		if (maxIndex != parentIndex)
		{
			Student* aux = pQueue->items[maxIndex];
			pQueue->items[maxIndex] = pQueue->items[parentIndex];
			pQueue->items[parentIndex] = aux;
			ReheapDown(pQueue, maxIndex);
		}
	}
}

Student* deque(PriorityQueue* pQueue)
{
	Student* result = NULL;
	if (pQueue->currentIndex > 0)
	{
		result = pQueue->items[0];
		pQueue->items[0] = pQueue->items[pQueue->currentIndex-1];
		pQueue->currentIndex--;
		ReheadDown(pQueue, 0);
	}
	return result;
}
