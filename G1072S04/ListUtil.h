#pragma once
#include "DataUtil.h"
typedef struct Node
{
	Student* info;
	struct Node* next;
}ListNode, *PListNode;

//void insertNode(ListNode** list, Student* stud)
void insertNode(PListNode* list, Student* stud)
{
	//PListNode node;
	ListNode* node = NULL;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->info = stud;
	node->next = *list;
	*list = node;
}
PListNode insertList(PListNode list, Student* stud)
{
	PListNode node = NULL;
	node = (PListNode)malloc(sizeof(ListNode));
	node->info = stud;
	node->next = list;
	return node;
}

void deleteList(ListNode** list)
{
	while (*list != NULL)
	{
		ListNode* tmp = *list;
		*list = tmp->next;
		printStudent(tmp->info);
		free(tmp->info->name);
		free(tmp->info);
		free(tmp);
	}
}

ListNode* deleteList(ListNode* list, const char* key)
{
	if (strcmp(list->info->name, key) == 0)
	{
		ListNode* tmp = list;
		list = list->next;
		printStudent(tmp->info);
		free(tmp->info->name);
		free(tmp->info);
		free(tmp);
		return list;
	}
	else
	{
		ListNode* tmp = list;
		while (tmp->next != NULL && strcmp(tmp->next->info->name, key) != 0)
			tmp = tmp->next;
		if (tmp->next != NULL)
		{

		}
	}
}