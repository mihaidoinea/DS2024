#pragma once
#include "DataUtil.h"
typedef struct HashN
{
	Student* info;
	struct HashN* next;
}HashNode, *PHashNode;
#define HASHT_SIZE 26

//hash table definition
//HashNode* *hashTable0;
//PHashNode* hashTable1;
//typedef HashNode** HashTable;
//HashTable hashTable2;

HashNode* createHashNode(Student* info)
{
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	node->info = info;
	node->next = NULL;
	return node;
}

int fHash(const char* key)
{
	return key[0] % HASHT_SIZE;
}

void deleteHT(HashNode** hashTable, const char* key)
{
	int index = fHash(key);
	HashNode* collisionList = hashTable[index];
	if (collisionList != NULL)
	{
		if (strcmp(collisionList->info->name, key) == 0)
		{
			hashTable[index] = collisionList->next;
			deleteStudent(collisionList->info);
			free(collisionList);
		}
		else
		{
			while (collisionList->next)
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
	//compute hash value
	int index = fHash(key);
	//get the list
	HashNode* collisionList = hashTable[index];
	//search for the key
	while (collisionList)
	{
		if (strcmp(key, collisionList->info->name) == 0)
			return collisionList->info;
		collisionList = collisionList->next;
	}
	return NULL;
}

void initHashTable(HashNode*** hashTable)
{
	if (*hashTable == NULL)
	{
		(*hashTable) = (HashNode**)malloc(sizeof(HashNode*) * HASHT_SIZE);
		/*for (int i = 0; i < HASHT_SIZE; i++)
		{
			(*hashTable)[i] = NULL;
		}*/
		memset((*hashTable), 0, sizeof(HashNode*) * HASHT_SIZE);
	}
}

void putHT(HashNode*** hashTable, Student* stud)
{
	if (*hashTable == NULL)
	{
		initHashTable(hashTable);
	}
	HashNode* node = createHashNode(stud);
	int hashValue = fHash(stud->name);

	/*HashNode* colList = (*hashTable)[hashValue];
	node->next = colList;
	(*hashTable)[hashValue] = node;*/
	node->next = (*hashTable)[hashValue];
	(*hashTable)[hashValue] = node;

}