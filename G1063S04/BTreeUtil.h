#pragma once
#include "DataUtil.h"
typedef struct NodeBST
{
	struct NodeBST* lChild;
	Student* info;
	struct NodeBST* rChild;
}BinaryTree, *PBinaryTree;

BinaryTree* createNodeBST(Student* info)
{
	BinaryTree* node = (BinaryTree*)malloc(sizeof(BinaryTree));
	node->info = info;
	node->lChild = node->rChild = NULL;
	return node;
}
void upsertBST(BinaryTree** root, Student* stud)
{
	if (*root == NULL)
	{
		*root = createNodeBST(stud);
	}
	else
	{
		if ((*root)->info->reference.intRef > stud->reference.intRef)
			upsertBST(&(*root)->lChild, stud);
		else if ((*root)->info->reference.intRef < stud->reference.intRef)
			upsertBST(&(*root)->rChild, stud);
		else
		{
			(*root)->info = stud;
		}
	}
}
//post-order: Root / Left / Right
//in-order: Left / Root / Right
//pre-order: Left / Right / Root
void TreeStructure(BinaryTree* root, int level)
{
	if (root != NULL)
	{
		for (int i = 0; i < level; i++)
			printf("\t");
		printf("%s\n", root->info->name);
		level++;
		TreeStructure(root->lChild, level);
		TreeStructure(root->rChild, level);
	}
	else
	{
		for (int i = 0; i < level; i++)
			printf("\t");
		printf("==\n");
	}
}