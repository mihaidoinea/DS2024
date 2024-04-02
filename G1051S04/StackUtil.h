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
void pushNode(StackNode** topStack, Student* stud)
{
	StackNode* node = createStackNode(stud);
	node->next = *topStack;
	*topStack = node;
}
Student* peekNode(StackNode** topStack)
{
	Student* result = NULL;
	if (*topStack != NULL)
	{
		result = (*topStack)->info;
	}
	return result;
}
Student* popNode(StackNode** topStack)
{
	Student* result = NULL;
	if (*topStack != NULL)
	{
		result = (*topStack)->info;
		StackNode* tmp = *topStack;
		*topStack = tmp->next;
		free(tmp);
	}
	return result;
}

void displayStack(StackNode** topStack)
{

}

void  deleteStack(StackNode** topStack)
{
	Student* info = NULL;
	while ((info = popNode(topStack)) != NULL)
	{
		printStudent(info);
	}
}