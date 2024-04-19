#pragma once
#include "DataUtil.h"
#include "stdbool.h"
#include "StackUtil.h"

typedef struct NodeL
{
	struct NodeL* prev;
	Student* info;
	struct NodeL* next;
}ListNode, *PListNode;

void deleteNode(ListNode* node)
{
	if (node != NULL)
	{
		deleteStudent(node->info);
		free(node);
	}
}

ListNode* createListNode(Student* stud)
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
//	ListNode* node = createListNode(stud);
//	node->next = *list;
//	*list = node;
//}
PListNode insertHead_SLNode(PListNode list, Student* stud)
{
	PListNode node = createListNode(stud);
	node->next = list;
	return node;
}

void insertTail_SLNode(ListNode** list, Student* stud)
{
	ListNode* node = createListNode(stud);
	if (*list == NULL)
		*list = node;
	else
	{
		ListNode* tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

void displayList(ListNode* head)
{
	while (head)
	{
		printStudent(head->info);
		head = head->next;
	}
}

void displayNormalAndReversed(ListNode* head) {
	while (head->next) {
		printStudent(head->info);
		head = head->next;
	}
	printStudent(head->info);
	printf("\n");
	printf("Reversed order:\n");
	while (head) {
		printStudent(head->info);
		head = head->prev;
	}
}

void insertTail_DLNode(ListNode** list, Student* stud)
{
	ListNode* node = createListNode(stud);
	if (*list == NULL)
	{
		*list = node;
	}
	else
	{
		ListNode* tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		node->prev = tmp;
		tmp->next = node;
	}
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
	if (list)
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
}
bool checkIfMirrored(ListNode* list1, ListNode* list2)
{
	StackNode* stack = NULL;
	ListNode* aux = list1;
	while (aux)
	{
		pushNode(&stack, aux->info);
		aux = aux->next;
	}
	while (peekNode(stack) != NULL)
	{
		Student* info = popNode(&stack);
		if (list2 == NULL || (list2 != NULL && info != list2->info))
			return false;
		list2 = list2->next;
	}
	return true;
}

ListNode* convert(ListNode* list1)
{
	ListNode* doubleLL = NULL;
	ListNode* middleLL = NULL;
	while (list1)
	{
		Student* info = list1->info;
		ListNode* node1 = createListNode(info);
		ListNode* node2 = createListNode(info);
		if (doubleLL == NULL)
		{
			node1->next = node2;
			node2->prev = node1;
			doubleLL = middleLL = node1;
		}
		else
		{
			node1->next = node2;
			node2->prev = node1;
			node1->prev = middleLL;
			node2->next = middleLL->next;
			middleLL->next = node1;
			node2->next->prev = node2;
			middleLL = node1;
		}
		list1 = list1->next;
	}
	return doubleLL;
}