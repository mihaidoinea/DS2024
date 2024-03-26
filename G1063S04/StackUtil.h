#pragma once
#include "DataUtil.h"
typedef struct Node
{
	Student* info;
	struct Node* next;
}StackNode, *PStackNode;

StackNode* createNode(Student* info)
{
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->info = info;
	node->next = NULL;
	return node;
}
void pushNode(StackNode** stack, Student* info)
{
	StackNode* node = createNode(info);
	node->next = *stack;
	*stack = node;
}
Student* popNode(StackNode** stack)
{
	Student* info = NULL;
	if (*stack != NULL)
	{
		info = (*stack)->info;
		StackNode* tmp = (*stack);
		(*stack) = tmp->next;
		free(tmp);
	}
	return info;
}