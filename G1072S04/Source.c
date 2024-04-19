#define _CRT_SECURE_NO_WARNINGS
#include "StackUtil.h"
#include "ListUtil.h"
#include "stdbool.h"

#define LINE_SIZE 256
void main()
{

	ListNode* list1 = NULL;
	ListNode* list2 = NULL;
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
			insertTail_SLNode(&list1, stud);
			//insertTail_SLNode(&list1, stud);

			list2 = insertHead_SLNode(list2, stud);
		}

		//data structure operation
		bool isMirrored = checkIfMirrored(list1, list2);
		printf("Are mirrored: %d\n", isMirrored);

		ListNode* mirroredDLList = convert(list1);
		displayList(mirroredDLList);

	}
}
