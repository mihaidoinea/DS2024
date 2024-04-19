#pragma once
#include "DataUtil.h"

#define HT_INITIAL_SIZE 3

typedef struct HashT
{
	Student** items;
	int size;
}HashTableLP;

int fHash(const char* key, int size)
{
	int hashValue = 0;
	for (int i = 0; i < strlen(key); i++)
	{
		hashValue += key[i] * (strlen(key) - i);
	}
	return hashValue % size;
}
void putStudent(HashTableLP*, Student*);

void resizeHT(HashTableLP* hashTable)
{
	Student** aux = hashTable->items;
	hashTable->items = (Student**)malloc(sizeof(Student*) * hashTable->size * 2);
	memset(hashTable->items, 0, sizeof(Student*) * hashTable->size * 2);
	hashTable->size *= 2;
	for (int index = 0; index < hashTable->size / 2; index++)
	{
		Student* stud = aux[index];
		if (stud != NULL)
		{
			putStudent(hashTable, stud);
		}
	}
}

int linearProbing(HashTableLP* hashTable, const char* key, int index)
{
	while (hashTable->items[index] != NULL)
	{
		index++;
		if (hashTable->size == index)
		{
			resizeHT(hashTable);
			index = fHash(key, hashTable->size);
		}
	}
	return index;
}
void putStudent(HashTableLP* hashTable, Student* stud)
{
	if (hashTable->items == NULL)
	{
		hashTable->items = (Student**)malloc(sizeof(Student*)*HT_INITIAL_SIZE);
		memset(hashTable->items, 0, sizeof(Student*) * HT_INITIAL_SIZE);
		hashTable->size = HT_INITIAL_SIZE;
	}
	int index = fHash(stud->name, hashTable->size);
	if (hashTable->items[index] != NULL)
	{
		index = linearProbing(hashTable, stud->name, index);
	}
	hashTable->items[index] = stud;
}
void displayStudents(HashTableLP hashTable)
{
	for (int index = 0; index < hashTable.size; index++)
	{ 
		printStudent(hashTable.items[index]);
	}
}