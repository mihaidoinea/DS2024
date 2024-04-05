#pragma once
#include "DataUtil.h"
typedef struct NodeQ
{
	Student* info;
	struct NodeQ* next;
}QueueNode, * PQueueNode;

QueueNode* createQueueNode(Student* info)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->info = info;
	node->next = NULL;
	return node;
}
void putNode(QueueNode** tailQueue, Student* stud)
{
	QueueNode* node = createQueueNode(stud);
	if (*tailQueue == NULL)
		node->next = node;
	else
	{
		node->next = (*tailQueue)->next;
		(*tailQueue)->next = node;
	}
	*tailQueue = node;
}

Student* peekNode(QueueNode* tailQueue)
{
	Student* result = NULL;
	if (tailQueue != NULL)
	{
		result = tailQueue->next->info;
	}
	return result;
}

Student* getNode(QueueNode** tailQueue)
{
	Student* result = NULL;
	if (*tailQueue != NULL)
	{
		result = (*tailQueue)->next->info;
		if ((*tailQueue)->next == (*tailQueue))
		{
			free(*tailQueue);
			*tailQueue = NULL;
		}
		else
		{
			QueueNode* head = (*tailQueue)->next;
			(*tailQueue)->next = head->next;
			free(head);
		}
	}
	return result;
}
void displayQueue(QueueNode** tailQueue)
{
	Student* info = peekNode(*tailQueue);
	Student* tmp = NULL;
	while (tmp != info)
	{
		tmp = getNode(tailQueue);
		printStudent(tmp);
		putNode(tailQueue, tmp);
		tmp = peekNode(*tailQueue);
	}
}