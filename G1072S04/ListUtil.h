#pragma once
#include "DataUtil.h"
typedef struct Node
{
	struct Node* prev;
	Student* info;
	struct Node* next;
}ListNode, *PListNode;

void deleteNode(ListNode* node)
{
	if (node != NULL)
	{
		deleteStudent(node->info);
		free(node);
	}
}

ListNode* createNode(Student* stud)
{
	ListNode* node = NULL;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->info = stud;
	node->next = node->prev = NULL;
	return node;
}

//void insertNode(ListNode** list, Student* stud)
//void insertHead_SLNode(PListNode* list, Student* stud)
//{
//	//PListNode node;
//	ListNode* node = createNode(stud);
//	node->next = *list;
//	*list = node;
//}
PListNode insertHead_SLNode(PListNode list, Student* stud)
{
	PListNode node = createNode(stud);
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

ListNode* deleteNodeByKey(ListNode* list, const char* key)
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
			ListNode* aux = tmp->next;
			tmp->next = aux->next; //tmp->next->next;
			deleteNode(aux);
		}
	}
}