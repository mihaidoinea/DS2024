#define _CRT_SECURE_NO_WARNINGS
#include "DataUtil.h"
#include "ListUtil.h"

#define LINE_SIZE 256
void main()
{
	struct Node list0 = {.info = NULL, .next = NULL};
	struct Node* list1 = NULL;
	ListNode list2 = { .info = NULL, .next = NULL };
	ListNode* list3 = NULL;
	PListNode list4 = NULL;
	ListNode* headList = NULL;

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
			//printStudent(stud);
			//ListNode* node = createNode(stud);
			//insertStudent(&headList, stud);
			headList = insertHead_SLNode(headList, stud);
		}
		//data structure operation
		deleteList(&headList);
		headList = deleteNodeByKey(headList, "Albu Cristina");
	}
}
