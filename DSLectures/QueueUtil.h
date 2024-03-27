#pragma once
#include "DataUtil.h"
typedef struct NodeQ
{
	struct NodeQ* prev;
	Student* inf;
	struct NodeQ* next;
}QueueNode, *PQueueNode;

