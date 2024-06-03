#include "stdlib.h"
#include "stdio.h"

typedef struct BSTNode
{
	struct BSTNode* left;
	struct Arrival* info;
	struct BSTNode* right;
}BST;
typedef struct Arrival
{
	char* trainCode;
	char* comingFrom;
	char* arrivalTime;
	unsigned short delay;
	unsigned short passengers;
}Arrival;

#define LINE_SIZE 255
Arrival* createArrival(const char* code, const char* src, const char* time, unsigned short delay,
	unsigned short pass)
{
	Arrival* node = (Arrival*)malloc(sizeof(Arrival));
	node->arrivalTime = (char*)malloc(strlen(time)+1);
	strcpy(node->arrivalTime, time);
	node->comingFrom = (char*)malloc(strlen(src)+1);
	strcpy(node->comingFrom, src);
	node->trainCode = (char*)malloc(strlen(code)+1);
	strcpy(node->trainCode, code);
	node->delay = delay;
	node->passengers = pass;
	return node;
}

BST* createNode(Arrival* info)
{
	BST* node = (BST*)malloc(sizeof(BST));
	node->left = node->right = NULL;
	node->info = info;
	return node;
}

void insert(BST** root, Arrival* info)
{
	if (*root == NULL)
	{
		*root = createNode(info);
	}
	else
	{
		if (strcmp((*root)->info->arrivalTime, info->arrivalTime) > 0)
			insert(&(*root)->left, info);
		else if (strcmp((*root)->info->arrivalTime, info->arrivalTime) < 0)
			insert(&(*root)->right, info);
	}
}
void printArrivals(BST* root)
{
	if (root)
	{
		printArrivals(root->right);
		printf("%s\n", root->info->arrivalTime);
		printArrivals(root->left);
	}
}

void displayArrival(Arrival* info)
{
	printf("Train code:%s\n", info->trainCode);
	printf("City:%s\n", info->comingFrom);
	printf("Time:%s\n", info->arrivalTime);
	printf("Delay:%d\n", info->delay);
	printf("Passengers:%d\n", info->passengers);

}

Arrival* getLastTrain(BST* tree)
{
	if (tree)
	{
		while (tree->right)
			tree = tree->right;
	}
	return tree->info;
}
int getDelayedArrivals(BST* root)
{
	if (root != NULL)
	{
		if (root->info->delay > 0)
			return 1 + getDelayedArrivals(root->left) + getDelayedArrivals(root->right);
		else
			return getDelayedArrivals(root->left) + getDelayedArrivals(root->right);
	}
	else
		return 0;
}

void getPassFromCity(BST* root, const char* city, int* noPass)
{
	if (root != NULL)
	{
		if(strcmp(root->info->comingFrom, city)== 0)
			(*noPass) += root->info->passengers;
		getPassFromCity(root->left, city, noPass);
		getPassFromCity(root->right, city, noPass);
	}
}

Arrival** expand(Arrival** arrivals, int noEl)
{
	Arrival** result = (Arrival**)malloc(sizeof(Arrival*) * (noEl + 1));
	for (int i = 0; i < noEl; i++)
		result[i] = arrivals[i];
	return result;
}

void convertToArray(BST* root, const char* time, Arrival*** arrivalsPath, int* noEl)
{
	if (root != NULL)
	{
		if (strcmp(root->info->arrivalTime, time) > 0)
			convertToArray(root->left, time, arrivalsPath, noEl);
		else
			if (strcmp(root->info->arrivalTime, time) < 0)
				convertToArray(root->right, time, arrivalsPath, noEl);
			else
			{
				*arrivalsPath = (Arrival**)malloc(sizeof(Arrival*)*1);
				(*arrivalsPath)[(*noEl)++] = root->info;
			}
		if (strcmp(root->info->arrivalTime, time) != 0)
		{
			*arrivalsPath = expand(*arrivalsPath, *noEl);
			(*arrivalsPath)[(*noEl)++] = root->info;
		}
	}
}

void main()
{
	BST* tree = NULL;
	FILE* pFile = fopen("BST.txt", "r");
	if (pFile)
	{
		char delimiter[] = ",";
		char* token = NULL;
		unsigned short delay, pass;
		char buffer[LINE_SIZE], code[LINE_SIZE], src[LINE_SIZE], time[LINE_SIZE];
		while (fgets(buffer, sizeof(buffer), pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(code, token);
			token = strtok(NULL, delimiter);
			strcpy(src, token);
			token = strtok(NULL, delimiter);
			strcpy(time, token);
			token = strtok(NULL, delimiter);
			delay = atoi(token);
			token = strtok(NULL, delimiter);
			pass = atoi(token);
			Arrival* arrival = createArrival(code, src, time, delay, pass);
			insert(&tree, arrival);
		}
		printArrivals(tree);
		Arrival* result = getLastTrain(tree);
		displayArrival(result);
		int count = getDelayedArrivals(tree);
		printf("No. of delayed arrivals:%d\n", count);
		int noPass = 0;
		getPassFromCity(tree, "Constanta", &noPass);
		printf("No. of passengers from Constanta:%d\n", noPass);
		int noEl = 0;
		Arrival** arrivalsPath = NULL;
		convertToArray(tree, "22:06", &arrivalsPath, &noEl);

	}
}