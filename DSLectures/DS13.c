#include "GraphUtil.h"
#define LINE_SIZE 256

void DS13()
{
	Student* students[10];
	memset(students, 0, sizeof(students));
	Node* graphList = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile)
	{
		char delimiter[] = ",";
		char* token = NULL;
		float income; int index = 0;
		unsigned short reference;
		char buffer[LINE_SIZE], name[LINE_SIZE];
		int i = 0;
		while (fgets(buffer, sizeof(buffer), pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);
			token = strtok(NULL, delimiter);
			income = atof(token);
			token = strtok(NULL, delimiter);
			reference = atoi(token);
			Student* stud = createStudent(name, income, reference);
			students[i++] = stud;
		}
		/**or (int i = 0; i < sizeof(students) / sizeof(Student*); i++)
		{
			if (students[i] != NULL)
				insertGraphNode(&graphList, students[i]);
		}
		//data structure operation
		addEdge(graphList, students[0], students[3]);*/
	}
}