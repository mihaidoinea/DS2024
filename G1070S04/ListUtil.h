#pragma once
#include "DataUtil.h"
typedef struct NodeL
{
	struct NodeL* prev;
	Student* info;
	struct NodeL* next;
}ListNode, *PListNode;

ListNode* createListNode(Student* stud)
{
	ListNode* node = NULL;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->info = stud;
	node->next = node->prev = NULL;
	return node;
}
ListNode* insertTail_DLNode(ListNode* headList, Student* stud)
{
	ListNode* node = createListNode(stud);
	if (headList == NULL)
		return node;
	else
	{
		ListNode* tmp = headList;
		while (tmp->next)
			tmp = tmp->next;
		//1.connect the node to the structure
		node->prev = tmp;
		//2.connect the structure to the node
		tmp->next = node;
		return headList;
	}
}

ListNode* insertHead_SLNode(ListNode* headList, Student* stud)
{
	ListNode* node = createListNode(stud);
	node->next = headList;
	return node;
}
//void insertHead_SLNode(ListNode** pHeadList, Student* stud)
//{
//	ListNode* node = createListNode(stud);
//	node->next = (*pHeadList);
//	(*pHeadList) = node;
//}
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
void deleteList(ListNode** pHeadList)
{
	while ((*pHeadList) != NULL)
	{
		ListNode* tmp = *pHeadList;
		*pHeadList = tmp->next;
		printStudent(tmp->info);
		deleteNode(tmp);
	}
}

void displayListBothWays(ListNode* head)
{
	if (head)
	{
		while (head->next)
		{
			printStudent(head->info);
			head = head->next;
		}
		printStudent(head->info);
		printf("----------Reversed order----------\n");
		while (head)
		{
			printStudent(head->info);
			head = head->prev;
		}
	}
}
void deleteNodeByKey(ListNode** head, const char* key)
{

}

ListNode* convert(ListNode* list)
{
	ListNode* headDL = NULL;
	ListNode* middleDL = NULL;
	if (list != NULL)
	{
		while (list)
		{
			Student* info = list->info;
			ListNode* node1 = createListNode(info);
			ListNode* node2 = createListNode(info);

			node1->next = node2;
			node2->prev = node1;

			if (headDL == NULL)
			{
				headDL = middleDL = node1;
				node1->prev = node2;
				node2->next = node1;
			}
			else
			{
				node1->prev = middleDL;
				node2->next = middleDL->next;
				middleDL->next = node1;
				node2->next->prev = node2;
				middleDL = node1;
			}

			list = list->next;
		}
	}
	return headDL;
}

void displayListBothWaysCircular(ListNode* list)
{
	ListNode* head = list;
	if (head != NULL)
	{
		do
		{
			printStudent(list->info);
			list = list->next;
		} while (list != head);
		ListNode* tail = head->prev;
		printf("--------Reverse order-----------\n");
		do
		{
			printStudent(tail->info);
			tail = tail->prev;
		} while (tail != head);
	}
}

