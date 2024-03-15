#pragma once
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
void insertStudent(ListNode** pHeadList, Student* stud)
{
	ListNode* node = createNode(stud);
	//connect the node to the struct
	if (*pHeadList == NULL)
		*pHeadList = node;
	else
	{
		node->next = *pHeadList;
		(*pHeadList)->prev = node;
		*pHeadList = node;
	}

}
void deleteNode(ListNode* node)
{
	if (node != NULL)
	{
		deleteStudent(node->info);
		free(node);
	}
}
void deleteList(ListNode** pHeadList)
{
	while (*pHeadList != NULL)
	{
		ListNode* tmp = *pHeadList;
		*pHeadList = tmp->next;
		printStudent(tmp->info);
		deleteNode(tmp);
	}
}
