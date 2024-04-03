#pragma once
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
Student* peekNode(QueueNode* queueTail)
{
	Student* result = NULL;
	if (queueTail != NULL)
	{
		result = queueTail->next->info;
	}
	return result;
}

Student* getNode(QueueNode** queueTail)
{
	Student* result = NULL;
	if (*queueTail != NULL)
	{
		result = (*queueTail)->next->info;
		QueueNode* head = (*queueTail)->next;
		//if queue has 1 element only
		if (*queueTail == (*queueTail)->next)
		{
			*queueTail = NULL;
		}
		else
		{
			(*queueTail)->next = head->next;
		}
		free(head);
	}
	return result;
}

void putNode(QueueNode** tail, Student* info)
{
	QueueNode* node = createQueueNode(info);
	if (*tail != NULL)
	{
		node->next = (*tail)->next;
		(*tail)->next = node;
	}
	else
	{
		node->next = node;
	}
	*tail = node;
}