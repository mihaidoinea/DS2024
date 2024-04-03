#pragma once
#include "DataUtil.h"
typedef struct NodeS
{
	Student* info;
	struct NodeS* next;
}StackNode, *PStackNode;

StackNode* createStackNode(Student* info)
{
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->info = info;
	node->next = NULL;
	return node;
}
void pushNode(StackNode** stack, Student* info)
{
	StackNode* node = createStackNode(info);
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