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
	node->next = (*stack);
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
void deleteStack(StackNode** stack)
{
	while (*stack)
	{
		Student* info = popNode(stack);
		printStudent(info);
		deleteStudent(info);
	}
}

void displayStack(StackNode** stack)
{
	StackNode* tmpStack = NULL;
	while (*stack)
	{
		Student* info = popNode(stack);
		printStudent(info);
		pushNode(&tmpStack, info);
	}
	while (tmpStack)
	{
		pushNode(stack, popNode(&tmpStack));
	}
}