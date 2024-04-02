#pragma once
typedef struct Node
{
	Student* info;
	struct Node* next;
}QueueNode, * PQueueNode;

QueueNode* createQueueNode(Student* info)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->info = info;
	node->next = NULL;
	return node;
}
