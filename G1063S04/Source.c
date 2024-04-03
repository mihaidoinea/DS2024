#define _CRT_SECURE_NO_WARNINGS
#include "DataUtil.h"
#include "QueueUtil.h"
#include "ListUtil.h"
#define LINE_SIZE 256

void main()
{
	QueueNode* queueTail = NULL;

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
			putNode(&queueTail, stud);
		}
		Student* info = NULL;
		while ((info = getNode(&queueTail)) != NULL)
		{
			printStudent(info);
		}
		//deleteQueue(&queueTail);
	}
}