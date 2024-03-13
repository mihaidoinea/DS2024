#include "DataUtil.h"

void main()
{
	FILE* pFile = fopen("Data.txt", "r");
	if (pFile)
	{
		char lineBuffer[LINE_SIZE], name[LINE_SIZE];
		float income = 0.0; unsigned short ref;
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
			printStudent(stud);
		}
	}
}
