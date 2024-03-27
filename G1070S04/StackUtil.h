#pragma once
#include "DataUtil.h"
typedef struct NodeS
{
	Student* info;
	struct NodeS* next;
}StackNode, *PStackNode;

StackNode* createStackNode(Student* info)
{
	//allocate memory
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	//init node
	node->info = info;
	node->next = NULL;
	return node;
}

StackNode* pushNode(StackNode* stack, Student* info)
{
	StackNode* node = createStackNode(info);
	node->next = stack;
	return node;
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
		Student* inf = popNode(stack);
		printStudent(inf);
		deleteStudent(inf);
	}
}
void displayStack(StackNode** stack)
{
	StackNode* tmpStack = NULL;
	while (*stack)
	{
		Student* info = popNode(stack);
		printStudent(info);
		tmpStack = pushNode(tmpStack, info);
	}
	while (tmpStack)
	{
		Student* inf = popNode(&tmpStack);
		*stack = pushNode(*stack, inf);
	}
}