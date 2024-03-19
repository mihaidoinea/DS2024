#pragma once
#include "main.h"
#include "DataUtil.h"
typedef struct Node
{
	Student* info;
	struct Node* next;
	struct Node* prev;
}ListNode, *PListNode;

ListNode* createNode(Student* stud)
{
	ListNode* node = NULL;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->info = stud;
	node->next = node->prev = NULL;
	return node;
}
void deleteNode(ListNode* node)
{
	if (node != NULL)
	{
		//free(node->info->name);
		//free(node->info);
		deleteStudent(node->info);
		free(node);
	}
}

void insertStudentDL(ListNode** headList, Student* stud)
{
	ListNode* node = createNode(stud);
	if (*headList != NULL)
	{
		node->next = *headList;
		(*headList)->prev = node;
	}
	*headList = node;
}
void traverseList(ListNode* headList)
{
	//while (headList && headList->next != NULL)
	//{
	//	printStudent(headList->info);
	//	headList = headList->next;
	//}
	//printStudent(headList);
	if (headList)
	{
		do
		{
			printStudent(headList->info);
			headList = headList->next;
		} while (headList->next != NULL);
		printf("----------------Reverse order-----------------\n");
		while (headList)
		{
			printStudent(headList->info);
			headList = headList->prev;
		}
	}
}
void deleteList(ListNode** headList)
{
	while (*headList != NULL)
	{
		ListNode* tmp = *headList;
		*headList = (*headList)->next;
		printStudent(tmp->info);
		deleteNode(tmp);
	}
}

ListNode* insertStudentSL(ListNode* headList, Student* stud)
{
	ListNode* node = createNode(stud);
	node->next = headList;
	return node;
}
//void insertStudentSL(ListNode** headList, Student* stud)
//{
//	ListNode* node = createNode(stud);
//	node->next = *headList;
//	*headList = node;
//}
//void deleteStudent(ListNode** headList, const char* name)
//{
//	PListNode tmp = *headList;
//	
//}