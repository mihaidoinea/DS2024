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