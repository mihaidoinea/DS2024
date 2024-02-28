#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "stdlib.h"
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
void main()
{
	Student* agenda[10];
	memset(agenda, 0, sizeof(agenda));
	FILE* pFile = fopen("Data.txt","r");
	if (pFile)
	{
		char* token = NULL; int index = 0;
		char buffer[LINE_SIZE], name[LINE_SIZE];
		float income; unsigned short reference;
		char delimiters[] = ",\n";
		while (fgets(buffer, sizeof(buffer), pFile))
		{
			token = strtok(buffer, delimiters);
			strcpy(name, token);
			token = strtok(NULL, delimiters);
			income = atof(token);
			token = strtok(NULL, delimiters);
			reference = atoi(token);
			Student* stud = createStudent(name, income, reference);
			agenda[index++] = stud;
		}

		for (int i = 0; i < sizeof(agenda) / sizeof(Student*); i++)
		{
			if (agenda[i] != NULL)
			{
				printStudent(agenda[i]);
				free(agenda[i]->name);
				free(agenda[i]);
				agenda[i] = NULL;
			}
		}
	}
}
Student* createStudent(const char* name, float income, 
	unsigned short reference)
{
	//1.Define a variable
	Student* stud = NULL;
	//2.Allocate memory
	stud = (Student*)malloc(sizeof(Student));
	//3.Init attributes
	stud->name = (char*)malloc(strlen(name) + 1);
	strcpy(stud->name, name);
	stud->income = income;
	stud->reference.extRef = reference;
	//4.Return pointer to useful info
	return stud;
}