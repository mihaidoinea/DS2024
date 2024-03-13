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
typedef struct BitReference
{
	unsigned int reference : 8;
	unsigned int univId : 7;
	unsigned int type : 1;
}BitReference;


#define LINE_SIZE 256
Student* createStudent(const char*, float, unsigned short);
void printStudent(Student*);

void main()
{
	//Student** agenda = NULL;
	Student* agenda;
	int size = 0;
	//memset(agenda, 0, sizeof(agenda));
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
			//agenda[index++] = stud;
			insertStudent(&agenda, stud, &size);
		}

		for (int i = 0; i < sizeof(agenda)/sizeof(Student*); i++)
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

void insertStudent(Student*** vector, Student* stud, int* size)
{
	Student** tmp = (Student**)malloc(sizeof(Student*) * (*size + 1));
	int k = 0, i = 0;
	while (i < *size && stud->income>(*vector)[i]->income)
	{
		tmp[k++] = (*vector)[i++];
	}
	tmp[k++] = stud;
	while (i < *size)
	{
		tmp[k++] = (*vector)[i++];
	}
	free(*vector);
	*vector = tmp;
	(*size)++;
}

void printStudent(Student* stud)
{
	if (stud)
	{
		printf("Name: %s\n", stud->name);
		printf("Income: %f\n", stud->income);
		BitReference* ptrReference = &stud->reference.extRef;
		if (ptrReference->type == 1)
		{
			printf("University id: %d\n", ptrReference->univId);
		}
		printf("Student reference: %d\n", ptrReference->reference);
		
		/*
		if (stud->reference.extRef >> 15 != 0)
		{
			printf("Student reference: %d\n", stud->reference.extRef);
			char univId = stud->reference.extRef >> 8 & 127;
			printf("University id: %d\n", univId);
			//printf("Student reference: %d\n", stud->reference.intRef);
			printf("Student reference: %d\n", stud->reference.extRef & 255);
		}
		else
		{
			printf("Student reference: %d\n", stud->reference.intRef);
		}*/
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