#pragma once
#include "DataUtil.h"
typedef struct NodeBST
{
	struct NodeBST* lChild;
	Student* info;
	struct NodeBST* rChild;
	short bFactor;
}BinaryTree, *PBinaryTree;

BinaryTree* createNodeBST(Student* info)
{
	BinaryTree* node = (BinaryTree*)malloc(sizeof(BinaryTree));
	node->info = info;
	node->lChild = node->rChild = NULL;
	node->bFactor = 0;
	return node;
}

short getHeight(BinaryTree* root)
{
	if (root != NULL)
		return 1 + max(getHeight(root->lChild), getHeight(root->rChild));
	else
		return 0;
}
BinaryTree* rightRotation(BinaryTree* pivot)
{
	BinaryTree* desc = pivot->lChild;
	pivot->lChild = desc->rChild;
	desc->rChild = pivot;
	return desc;
}

BinaryTree* leftRotation(BinaryTree* pivot)
{
	BinaryTree* desc = pivot->rChild;
	pivot->rChild = desc->lChild;
	desc->lChild = pivot;
	return desc;
}

void rebalance(BinaryTree** root)
{
	(*root)->bFactor = getHeight((*root)->rChild) - getHeight((*root)->lChild);
	if ((*root)->bFactor == -2)
	{
		BinaryTree* desc = (*root)->lChild;
		if (desc->bFactor == -1)
			*root = rightRotation(*root);
		else
		{
			(*root)->lChild = leftRotation(desc);
			*root = rightRotation(*root);
		}
	}
	else if ((*root)->bFactor == 2)
	{
		BinaryTree* desc = (*root)->rChild;
		if (desc->bFactor == -1)
			(*root)->rChild = rightRotation(desc);
		*root = leftRotation(*root);
	}
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
	rebalance(root);
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
		printf("%s:%d\n", root->info->name, root->info->reference.intRef);
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

void deleteNodeByKey(BinaryTree** root, int key)
{
	if (*root != NULL)
	{
		if ((*root)->info->reference.intRef > key)
			deleteNodeByKey(&(*root)->lChild, key);
		else if ((*root)->info->reference.intRef < key)
			deleteNodeByKey(&(*root)->rChild, key;
		else
		{
			//node is a leaf
			if ((*root)->lChild == NULL && (*root)->rChild == NULL)
			{
				deleteStudent((*root)->info);
				free(*root);
				*root = NULL;
			}
			else if ((*root)->lChild == NULL || (*root)->rChild == NULL)
			{
				BinaryTree* tmp = *root;
				*root = (*root)->lChild != NULL ? (*root)->lChild : (*root)->rChild;
				deleteStudent(tmp->info);
				free(tmp);
			}
			else
			{
				deleteFullNode(root, &(*root)->lChild);
			}
		}
	}
}