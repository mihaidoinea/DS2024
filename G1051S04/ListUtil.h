#pragma once
#include "main.h"
#include "DataUtil.h"
typedef struct Node
{
	Student* info;
	struct Node* next;
}ListNode, * PListNode;

ListNode* createNode(Student* stud)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->info = stud;
	node->next = NULL;
	return node;
}
void deleteNode(ListNode* node)
{
	if (node != NULL)
	{
		deleteStudent(node->info);
		free(node);
	}
}
void insertStudent(ListNode** headList, Student* stud)
{
	ListNode* node = createNode(stud);
	node->next = *headList;
	*headList = node;
}
ListNode* insertListStudent(ListNode* headList, Student* stud)
{
	ListNode* node = createNode(stud);
	node->next = headList;
	return node;
}
void displayList(ListNode* headList)
{
	while (headList)
	{
		printStudent(headList->info);
		headList = headList->next;
	}
}
void deleteNodeByKey(PListNode* pHeadList, const char* key)
{
	if (*pHeadList != NULL)
	{
		if (strcmp((*pHeadList)->info->name, key) == 0)
		{
			ListNode* tmp = *pHeadList;
			*pHeadList = tmp->next;
			deleteNode(tmp);
		}
		else
		{
			ListNode* iterator = *pHeadList;
			while (iterator->next != NULL &&
				strcmp(iterator->next->info->name, key) != 0)
			{
				iterator = iterator->next;
			}
			if (iterator->next != NULL)
			{
				ListNode* tmp = iterator->next;
				iterator->next = tmp->next;
				deleteNode(tmp);
			}
		}
	}
}