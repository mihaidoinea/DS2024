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
Student* peekNode(StackNode* stack)
{
	Student* info = NULL;
	if (stack != NULL)
	{
		info = stack->info;
	}
	return info;
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
void displayStack(StackNode** stack)
{
	StackNode* tmp = NULL;
	Student* info = NULL;
	while ((info = peekNode(*stack)) != NULL)
	{
		popNode(stack);
		pushNode(&tmp, info);
		printStudent(info);
	}
	while ((info = popNode(&tmp)) != NULL)
	{
		pushNode(stack, info);
	}
}