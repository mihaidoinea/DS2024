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
typedef struct Student
{
	char* name;
	float income;
	Reference reference;
}Student;


typedef struct BitReference
{
	unsigned short ref : 8;
	short uniId : 7;
	short type : 1;
}BitReference;

void printStudent(Student*);
Student* createStudent(const char*, float, unsigned short);
#define LINE_SIZE 256

void main()
{
	Student* catalog[10];
	memset(catalog, 0, sizeof(catalog));

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile)
	{
		/*
		char delimiters1[] = "\n,";
		delimiters1[1] = '2';

		char* delimiters2 = "\n,";
		delimiters2[1] = '2';

		int value1 = 8;
		int value2 = 9;
		int* const pdelimiters1 = &value1;
		//pdelimiters1 = &value2;
		*pdelimiters1 = 4;
		
		int const* pdelimiters2 = &value2;
		const int* pdelimiters3 = &value2;
		pdelimiters2 = &value1;
		//*pdelimiters2 = 7;

		const int* const pdelimiter = &value1;
		*/
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
			catalog[index++] = stud;
			printStudent(stud);
		}
	}
}
void printStudent(Student* stud)
{
	if (stud != NULL)
	{
		printf("Name: %s\n", stud->name);
		printf("Income: %f\n", stud->income);
		BitReference* pRef = &stud->reference.extRef;
		if (pRef->type == 0)
		{
			printf("Reference: %d\n", pRef->ref);
		}
		else
		{
			printf("Reference ext: %d\n", stud->reference.extRef);
			printf("University id: %d\n", pRef->uniId);
			printf("Reference: %d\n", pRef->ref);
		}
		/*
		if (stud->reference.extRef >> 15 == 0)
		{
			printf("Reference: %d\n", stud->reference.intRef);
		}
		else
		{
			printf("Reference ext: %d\n", stud->reference.extRef);
			char univId = stud->reference.extRef >> 8 & 127;
			printf("University id: %d\n", univId);
			printf("Reference: %d\n", stud->reference.extRef & 255);
		}*/
		printf("\n");
	}
}

Student* createStudent(const char* name, float income, unsigned short ref)
{
	//1.define variable
	Student* stud = NULL;
	//2.allocate memory
	stud = (Student*)malloc(sizeof(Student));
	//3.initialize attributes
	stud->name = (char*)malloc(strlen(name) + 1);
	strcpy(stud->name, name);
	stud->income = income;
	stud->reference.extRef = ref;
	//4.return variable
	return stud;
}