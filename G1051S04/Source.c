#define _CRT_SECURE_NO_WARNINGS
#include "DataUtil.h"
#include "ListUtil.h"
#include "StackUtil.h"

#define LINE_SIZE 256

void main()
{
	StackNode* topStack = NULL;

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
			pushNode(&topStack, stud);
			//topStack = pushNode(topStack, stud);
		}
		//data structure operation
		Student* info = popNode(&topStack);
		printStudent(info);

		displayStack(&topStack);

		deleteStack(&topStack);
	}
}