#pragma once
#include "DataUtil.h"
typedef struct NodeBST
{
	struct NodeBST* lChild;
	Student* info;
	struct NodeBST* rChild;
	int bFactor;
}BinarySearchTree, *PBinarySearchTree;

BinarySearchTree* createTreeNode(Student* info)
{
	BinarySearchTree* node = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
	node->info = info;
	node->lChild = node->rChild = NULL;
	node->bFactor = 0;
	return node;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int getHeight(BinarySearchTree* root)
{
	if (root == NULL)
		return 0;
	else
	{
		return 1 + max(getHeight(root->lChild), getHeight(root->rChild));
	}
}
BinarySearchTree* leftRotation(BinarySearchTree* pivot)
{
	BinarySearchTree* desc = pivot->rChild;
	pivot->rChild = desc->lChild;
	desc->lChild = pivot;
	return desc;
}
BinarySearchTree* rightRotation(BinarySearchTree* pivot)
{
	BinarySearchTree* desc = pivot->lChild;
	pivot->lChild = desc->rChild;
	desc->rChild = pivot;
	return desc;
}
void rebalance(BinarySearchTree** root)
{
	(*root)->bFactor = getHeight((*root)->rChild) - getHeight((*root)->lChild);
	if ((*root)->bFactor == 2)
	{
		BinarySearchTree* desc = (*root)->rChild;
		if (desc->bFactor == -1)
			(*root)->rChild = rightRotation(desc);
		*root = leftRotation(*root);
	}
	else if ((*root)->bFactor == -2)
	{
		BinarySearchTree* desc = (*root)->lChild;
		if (desc->bFactor == 1)
			(*root)->lChild = leftRotation(desc);
		*root = rightRotation(*root);
	}
}

void upsert(PBinarySearchTree* root, Student* stud)
{
	if (*root == NULL)
	{
		*root = createTreeNode(stud);
	}
	else
	{
		if ((*root)->info->reference.intRef > stud->reference.intRef)
			upsert(&(*root)->lChild, stud);
		else if ((*root)->info->reference.intRef < stud->reference.intRef)
			upsert(&(*root)->rChild, stud);
		else
		{
			printf("Key already present, updating!");
			(*root)->info = stud;
		}
	}
	rebalance(root);
}
void displayTreeStructure(PBinarySearchTree root, int level)
{
	if (root != NULL)
	{
		for (int i = 0; i < level; i++)
			printf("\t");
		printf("%s:%d\n", root->info->name, root->info->reference.intRef);
		level++;
		displayTreeStructure(root->lChild, level);
		displayTreeStructure(root->rChild, level);
	}
	else
	{
		for (int i = 0; i < level; i++)
			printf("\t");
		printf("NULL\n");
	}
}
void deleteFullNode(BinarySearchTree** root, BinarySearchTree** rDesc)
{
	if ((*rDesc)->lChild)
		deleteFullNode(root, &(*rDesc)->lChild);
	else
	{
		deleteStudent((*root)->info);
		(*root)->info = (*rDesc)->info;
		BinarySearchTree* tmp = (*rDesc);
		*rDesc = (*rDesc)->rChild;
		free(tmp);
	}
}
void deleteNodeByKey(PBinarySearchTree* root, unsigned char key)
{
	if (*root != NULL)
	{
		if ((*root)->info->reference.intRef > key)
			deleteNodeByKey(&(*root)->lChild, key);
		else if ((*root)->info->reference.intRef < key)
			deleteNodeByKey(&(*root)->rChild, key);
		else
		{
			//node is a leaf
			if ((*root)->lChild == NULL && (*root)->rChild == NULL)
			{
				deleteStudent((*root)->info);
				free(*root);
				*root = NULL;
			}
			else if ((*root)->lChild == NULL || (*root)->rChild == NULL)//1 desc. node
			{
				BinarySearchTree* tmp = *root;
				*root = tmp->lChild != NULL ? tmp->lChild : tmp->rChild;
				deleteStudent(tmp->info);
				free(tmp);
			}
			else//2 desc. node
			{
				deleteFullNode(root, &(*root)->rChild);
			}
		}
	}
}
