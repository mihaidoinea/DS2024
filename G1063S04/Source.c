#define _CRT_SECURE_NO_WARNINGS
#include "GraphUtil.h"
#define LINE_SIZE 256

void main()
{
	Graph* graph = NULL;
	Student* input[10];
	memset(input, 0, sizeof(input));
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
			input[index++] = stud;
		}
		
		addEdge(&graph, input[0], input[4]);
		addEdge(&graph, input[1], input[4]);
		addEdge(&graph, input[1], input[6]);
		addEdge(&graph, input[2], input[5]);
		addEdge(&graph, input[2], input[6]);
		addEdge(&graph, input[3], input[1]);
		addEdge(&graph, input[4], input[2]);
		addEdge(&graph, input[5], input[0]);

		printGraph(graph);

	}
}