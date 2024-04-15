#define _CRT_SECURE_NO_WARNINGS
#include "HashUtil.h"
#define LINE_SIZE 256

void main()
{
	HashTable hashTable = {.buckets=NULL, .size = 0};
	//
	if (hashTable.buckets == NULL)
	{
		hashTable.buckets = (HashNode**)malloc(sizeof(HashNode*)*HASH_SIZE);
		memset(hashTable.buckets, 0, sizeof(HashNode*) * HASH_SIZE);
		hashTable.size = HASH_SIZE;
	}
	FILE* pFile = fopen("Data.txt", "r");
	if (pFile)
	{
		char delimiter[] = ",";
		char* token = NULL;
		float income; int index = 0;
		unsigned short reference;
		char buffer[LINE_SIZE], name[LINE_SIZE];
		while (fgets(buffer, sizeof(buffer), pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);
			token = strtok(NULL, delimiter);
			income = atof(token);
			token = strtok(NULL, delimiter);
			reference = atoi(token);
			Student* stud = createStudent(name, income, reference);
			putNode(hashTable, stud);
		}
		Student* info = getNode(hashTable, "Popescu Andrei");
		printStudent(info);

		//displayHashTable(hashTable);
		//deleteHashTable(hashTable);

		//Popa Maria / Paunescu Aline
		deleteNode(hashTable, "Paunescu Alina");

	}
}