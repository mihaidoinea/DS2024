#pragma once
#include "DataUtil.h"
#define HASHT_SIZE 26

typedef struct HashN
{
	Student* info;
	struct HashN* next;
}HashNode, *PHashNode;

typedef HashNode** HashTable;

int fHash(const char* key)
{
	return key[0] % HASHT_SIZE;
}

HashNode* createHashNode(Student* info)
{
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	node->info = info;
	node->next = NULL;
	return node;
}

void deleteHT(HashNode** hashTable, const char* key)
{
	//calculate hashValue
	int hashValue = fHash(key);
	//get the collision list
	HashNode* collisionList = hashTable[hashValue];
	//search and delete the key
	if (collisionList)
	{
		if (strcmp(collisionList->info->name, key) == 0)
		{
			hashTable[hashValue] = collisionList->next;
			deleteStudent(collisionList->info);
			free(collisionList);
		}
		else
		{
			while (collisionList && collisionList->next)
			{
				if (strcmp(collisionList->next->info->name, key) == 0)
				{
					HashNode* tmp = collisionList->next;
					collisionList->next = tmp->next;
					deleteStudent(tmp->info);
					free(tmp);
				}
				collisionList = collisionList->next;
			}
		}
	}
}

Student* getHT(HashNode** hashTable, const char* key)
{
	//calculate hashValue
	int hashValue = fHash(key);
	//get the collision list
	HashNode* collisionList = hashTable[hashValue];
	//search for the key
	while (collisionList)
	{
		if (strcmp(collisionList->info->name, key) == 0)
			return collisionList->info;
		collisionList = collisionList->next;
	}
	return NULL;
}

void putHT(HashNode*** hashTable, Student* stud)
{
	if (*hashTable == NULL)
	{
		(*hashTable) = (HashNode**)malloc(sizeof(HashNode*) * HASHT_SIZE);
		/*for (int i = 0; i < HASHT_SIZE; i++)
			(*hashTable)[i] = NULL;*/
		memset((*hashTable), 0, sizeof(HashNode*) * HASHT_SIZE);
	}
	HashNode* node = createHashNode(stud);
	int hashValue = fHash(stud->name);
	/*HashNode* collisionList = (*hashTable)[hashValue];
	node->next = collisionList;
	(*hashTable)[hashValue] = node;*/
	node->next = (*hashTable)[hashValue];
	(*hashTable)[hashValue] = node;
}

