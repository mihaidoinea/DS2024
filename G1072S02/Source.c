#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
union Reference
{
	unsigned char intRef;
	unsigned short extRef;
};
typedef union Reference Reference;
typedef struct Stud
{
	char* name;
	float income;
	Reference reference;
}Student;
#define LINE_SIZE 256
Student* createStudent(const char*, float, unsigned short);
void freeMemory(Student**);

void main()
{
	Student* agenda[10];
	memset(agenda, 0, sizeof(agenda));
	FILE* pFile = fopen("Data.txt", "r");
	if (pFile)
	{
		int index = 0;
		char buffer[LINE_SIZE], name[LINE_SIZE];
		char* token; float income; unsigned short ref;
		char delimiter[] = ",\n";
		while (fgets(buffer, sizeof(buffer), pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);
			token = strtok(NULL, delimiter);
			income = atof(token);
			token = strtok(NULL, delimiter);
			ref = atoi(token);
			Student* stud = createStudent(name, income, ref);
			agenda[index++] = stud;
		}
		freeMemory(agenda, sizeof(agenda)/sizeof(Student*));
	}
}
void freeMemory(Student** agenda, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (agenda[i] != NULL)
		{
			free(agenda[i]->name);
		}
		free(agenda[i]);
	}
}
Student* createStudent(const char* name, float income, unsigned short ref)
{
	//1.declare variable
	Student* stud = NULL;
	//2.allocate memory
	stud = (Student*)malloc(sizeof(Student));
	//3.init attributes
	stud->name = (char*)malloc(strlen(name) + 1);
	strcpy(stud->name, name);
	stud->income = income;
	stud->reference.extRef = ref;
	//4.return student
	return stud;
}