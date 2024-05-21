#pragma once
#include "DataUtil.h"
typedef struct NodeBST
{
	struct NodeBST* lChild;
	Student* info;
	struct NodeBST* rChild;
}BinarySearchTree, *PBinarySearchTree;

BinarySearchTree* createTreeNode(Student* info)
{
	BinarySearchTree* node = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
	node->info = info;
	node->lChild = node->rChild = NULL;
	return node;
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
				deleteFullNode();
			}
		}
	}
}