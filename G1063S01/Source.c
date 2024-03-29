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

void insertNumber(int**, int, int*);
Student* createStudent(const char*, float, unsigned short);
void printStudent(Student*);


typedef struct Letter
{
	int	:5;
	int sign : 1;
	int : 2;
} *PLetter;


void main()
{
	int* array = NULL;
	int number = 0; int size = 0;
	printf("Give a number: ");
	scanf("%d", &number);

	while (number != 0)
	{
		insertNumber(&array, number, &size);
		for (int i = 0; i < size; i++)
			printf("%d; ", array[i]);
		printf("\n");
		printf("Give a number: ");
		scanf("%d", &number);
	}

	Student student = { .name = "Popescu Maria", .income = 233.3, .reference = 2232 };
	Student* catalog[10];
	memset(catalog, NULL, sizeof(catalog));
	FILE* pFile = fopen("Data.txt", "r");
	if (pFile)
	{
		char lineBuffer[LINE_SIZE], name[LINE_SIZE];
		float income=0.0; unsigned short ref;
		char* token; char delimiter[] = "\n,";
		int index = 0;
		while (fgets(lineBuffer, sizeof(lineBuffer), pFile))
		{
			token = strtok(lineBuffer, delimiter);
			strcpy(name, token);
			token = strtok(NULL, delimiter);
			income = atof(token);
			token = strtok(NULL, delimiter);
			ref = atoi(token);
			Student* stud = createStudent(name, income, ref);
			catalog[index++] = stud;
			printStudent(stud);
		}
	}
}
void printStudent(Student* pStud)
{
	if (pStud != NULL)
	{
		PLetter ptrLetter;
		for (int i = 0; i < strlen(pStud->name); i++)
		{
			if (pStud->name[i] != ' ')
			{
				ptrLetter = &pStud->name[i];
				ptrLetter->sign = ~ptrLetter->sign;
			}
		}
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
	stud->name = (char*)malloc(strlen(name)+1);
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