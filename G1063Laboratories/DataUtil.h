#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 256
union Ref
{
	unsigned char intRef;
	unsigned short extRef;
};
typedef union Ref Reference;
struct Stud
{
	char* name;
	float income;
	Reference reference;
};
typedef struct Stud Student;

void printStudent(Student* pStud)
{
	if (pStud != NULL)
	{
		printf("Name: %s, income: %f\n", pStud->name, pStud->income);
		if (pStud->reference.extRef >> 15 == 1)
		{
			short uid = pStud->reference.extRef >> 8 & 127;
			printf("University ref: %d\n", uid);
			printf("External ref: %d\n", pStud->reference.intRef);
		}
		else
		{
			printf("Internal ref: %d\n", pStud->reference.intRef);
		}
	}
}

Student* createStudent(const char* name, float income, unsigned short ref)
{
	//1.define variable for info
	Student* stud = NULL;
	//2.memory allocation
	stud = (Student*)malloc(sizeof(Student));
	//3.init variable
	stud->name = (char*)malloc(strlen(name) + 1);
	strcpy(stud->name, name);
	stud->income = income;
	stud->reference.extRef = ref;
	//4.return variable
	return stud;
}


void insertNumber(int** masiv, int number, int* size)
{
	int* temp = (int*)malloc(sizeof(int) * (*size + 1));
	int k = 0, i = 0;
	while (i < *size && (*masiv)[i] < number)
	{
		temp[k++] = (*masiv)[i++];
	}
	temp[k++] = number;
	while (i < *size)
	{
		temp[k++] = (*masiv)[i++];
	}
	free(*masiv);
	*masiv = temp;
	(*size)++;
}