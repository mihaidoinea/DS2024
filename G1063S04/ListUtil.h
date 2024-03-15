#pragma once
#include "main.h"
#include "DataUtil.h"
typedef struct Node
{
	Student* info;
	struct Node* next;
}ListNode, *PListNode;

void insertStudent(ListNode** headList, Student* stud)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->info = stud;
	node->next = *headList;
	*headList = node;
}
ListNode* insertListStudent(ListNode* headList, Student* stud)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->info = stud;
	node->next = headList;
	return node;
}
void deleteStudent(ListNode** headList, const char* name)
{
	PListNode tmp = *headList;
	
}