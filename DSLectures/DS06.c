#include "QueueUtil.h"
#define LINE_SIZE 256
void DS06()
{
	//empty queue
	QueueNode* queue = NULL;

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
			putNode(&queue, stud);
		}
		//data structure operation
		Student* inf = NULL;
		while ((inf = popNode(&queue)) != NULL)
		{
			printStudent(inf);
		}
		
	}
}