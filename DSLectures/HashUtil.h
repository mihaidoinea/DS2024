#pragma once
#include "DataUtil.h"
#define HT_INITIAL_SIZE 3
typedef struct HTable
{
	Student** items;
	int size;
}HashTable;

void resizeHT(HashTable*);

void displayStudents(Student** agenda, int noEl)
{
	for (int i = 0; i < noEl; i++)
	{
		printf("Bucket %d:\n", i);
		printStudent(agenda[i]);
	}
}

int fhash(char key, int size)
{
	return key % size;
}


int linearProbing(HashTable* hTabel, char key, int index)
{
	while (hTabel->items[index] != NULL)
	{
		index++;
		if (hTabel->size == index)
		{
			printf("\n----------------Hash Table Items before Resize-------------------\n");
			displayStudents(hTabel->items, hTabel->size);
			resizeHT(hTabel);
			index = fhash(key, hTabel->size);
		}
	}
	return index;
}

void putHashTable(HashTable* hTable, Student* stud)
{
	if (hTable->size == 0)
	{
		hTable->items = (Student**)malloc(sizeof(Student*) * HT_INITIAL_SIZE);
		hTable->size = HT_INITIAL_SIZE;
		memset(hTable->items, 0, sizeof(Student*) * HT_INITIAL_SIZE);
	}
	int index = fhash(stud->reference.intRef, hTable->size);
	if (hTable->items[index] != NULL)
	{
		char key = stud->reference.intRef;
		index = linearProbing(hTable, key, index);
	}
	hTable->items[index] = stud;
}

void resizeHT(HashTable* hTable)
{
	Student** aux = hTable->items;
	hTable->size *= 3;
	hTable->items = (Student**)malloc(sizeof(Student*) * hTable->size);
	memset(hTable->items, 0, sizeof(Student*) * hTable->size);
	for (int index = 0; index < hTable->size / 3; index++)
	{
		Student* stud = aux[index];
		if (stud != NULL)
		{
			putHashTable(hTable, stud);
		}
	}
}