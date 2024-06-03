#define _CRT_SECURE_NO_WARNINGS
#include "GraphUtil.h"

#define LINE_SIZE 256

void main()
{
	Vertex* graph = NULL;
	Student* students[10];
	memset(students, 0, sizeof(students));

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
			students[index++] = stud;
		}

		addEdge(&graph, students[0], students[1]);
		addEdge(&graph, students[0], students[2]);
		addEdge(&graph, students[0], students[3]);
		addEdge(&graph, students[0], students[4]);
		addEdge(&graph, students[0], students[5]);
		addEdge(&graph, students[0], students[6]);
		addEdge(&graph, students[1], students[2]);
		addEdge(&graph, students[1], students[5]);
		addEdge(&graph, students[2], students[6]);
		addEdge(&graph, students[3], students[5]);
		addEdge(&graph, students[4], students[6]);
		addEdge(&graph, students[5], students[6]);

		displayGraph(graph);

		MatNode** adjacencyMatrix = NULL;
		int noEl = 7;
		adjacencyMatrix = (MatNode**)malloc(sizeof(MatNode*) * noEl);
		for (int i = 0; i < noEl; i++)
		{
			adjacencyMatrix[i] = (MatNode*)malloc(sizeof(MatNode) * noEl);
			memset(adjacencyMatrix[i], 0, sizeof(MatNode) * noEl);
		}
		convertListToMat(graph, adjacencyMatrix);
	}
}