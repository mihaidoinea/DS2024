#pragma once
#include "DataUtil.h"
typedef struct NodeQ
{
	Student* info;
	struct NodeQ* next;
}QueueNode, * PQueueNode;