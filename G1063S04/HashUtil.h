#pragma once
#include "DataUtil.h"
typedef struct NodeH
{
	Student* info;
	struct NodeH* next;
}HashNode, *PHashNode;

typedef struct HashT
{
	HashNode** buckets;
	int size;
}HashTable;
#define HASH_SIZE 26

HashNode* createHashNode(Student* info)
{
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	node->info = info;
	node->next = NULL;
	return node;
}

int fHash(char* key)
{
	return key[0] % HASH_SIZE;
}

Student* getNode(HashTable hashTable, const char* key)
{
	int hashValue = fHash(key);
	HashNode* node = hashTable.buckets[hashValue];
	while (node)
	{
		if (strcmp(node->info->name, key) == 0)
			return node->info;
		node = node->next;
	}
	return NULL;
}
void deleteNode(HashTable hashTable, const char* key)
{
	int hashValue = fHash(key);
	HashNode* node = hashTable.buckets[hashValue];
	if (node != NULL)
	{
		if (strcmp(node->info->name, key) == 0)
		{
			hashTable.buckets[hashValue] = node->next;
			deleteStudent(node->info);
			free(node);
		}
		else
		{
			while (node && node->next)
			{
				if (strcmp(node->next->info->name, key) == 0)
				{
					HashNode* tmp = node->next;
					node->next = tmp->next;
					deleteStudent(tmp->info);
					free(tmp);
				}
				node = node->next;
			}
		}
	}
}

void putNode(HashTable hashTable, Student* stud)
{
	HashNode* node = createHashNode(stud);
	int hashValue = fHash(stud->name);
	node->next = hashTable.buckets[hashValue];
	hashTable.buckets[hashValue] = node;
}