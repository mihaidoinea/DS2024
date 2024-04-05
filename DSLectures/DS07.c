#include "HashUtil.h"
#define LINE_SIZE 256

void main()
{
	FILE* pFile = fopen("Data.txt", "r");
	HashTable hashTable = { .items = NULL, .size = 0 };
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
			putHashTable(&hashTable, stud);
		}
		printf("\n----------------Hash Table Items--------------------\n");
		displayStudents(hashTable.items, hashTable.size);

		fclose(pFile);
	}
}