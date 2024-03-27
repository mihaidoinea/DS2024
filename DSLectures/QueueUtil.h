#pragma once
#include "DataUtil.h"
typedef struct NodeQ
{
	struct NodeQ* prev;
	Student* inf;
	struct NodeQ* next;
}QueueNode, *PQueueNode;

QueueNode* createQueueNode(Student* info)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->inf = info;
	node->next = node->prev = NULL;
	return node;
}
void putNode(QueueNode** queue, Student* stud)
{
	QueueNode* node = createQueueNode(stud);
	if (*queue == NULL)
	{
		node->next = node->prev = node;
		*queue = node;
	}
	else
	{
		//connect the node to the structure
		node->prev = (*queue)->prev;
		node->next = (*queue);
		//connect the structure to the node
		//(*queue)->prev->next = node;
		//(*queue)->prev = node;
		//or
		(*queue)->prev = node;
		node->prev->next = node;
	}
}
Student* popNode(QueueNode** queue)
{
	Student* info = NULL;
	if (*queue != NULL)
	{
		//one queue element
		if ((*queue)->next == (*queue) && (*queue)->prev == (*queue))
		{
			info = (*queue)->inf;
			free(*queue);
			*queue = NULL;
		}
		else
		{
			info = (*queue)->inf;
			QueueNode* tmp = (*queue);
			(*queue)->prev->next = (*queue)->next;
			(*queue)->next->prev = (*queue)->prev;
			*queue = (*queue)->next;
			free(tmp);
		}
	}
	return info;
}