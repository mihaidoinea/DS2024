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
		}
	}
}