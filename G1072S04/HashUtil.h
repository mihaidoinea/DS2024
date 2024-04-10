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

Student* getHT(HashNode** hashTable, const char* key)
{
	//compute hash value
	//get the list
	//search for the key
	//return result
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