#pragma once
#include "DataUtil.h"

typedef struct TreeN
{
	struct TreeN* left;
	Student* info;
	struct TreeN* right;
	int bFactor;
}TreeNode, * PTreeNode;

TreeNode* createTreeNode(Student* info)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->info = info;
	node->left = node->right = NULL;
	node->bFactor = 0;
	return node;
}
Student* getMax(TreeNode* root)
{
	while (root->right)
		root = root->right;
	return root->info;
}
// LS / RS /Root
void postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("Student: %s, reference: %d\n", root->info->name, root->info->reference.intRef);

	}
}
//LS / Root / RS
void inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);
		printf("Student: %s, reference: %d\n", root->info->name, root->info->reference.intRef);
		inorder(root->right);
	}
}
//Root / LS / RS
void preorder(TreeNode* root)
{
	if (root)
	{
		printf("Student: %s, reference: %d\n", root->info->name, root->info->reference.intRef);
		preorder(root->left);
		preorder(root->right);
	}
}
int getHeight(TreeNode* root)
{
	if (root != NULL)
		return 1 + max(getHeight(root->left), getHeight(root->right));
	else
		return 0;
}
TreeNode* rightRotation(TreeNode* pivot)
{
	TreeNode* desc = pivot->left;
	pivot->left = desc->right;
	desc->right = pivot;
	return desc;
}
TreeNode* leftRotation(TreeNode* pivot)
{
	TreeNode* desc = pivot->right;
	pivot->right = desc->left;
	desc->left = pivot;
	return desc;
}
void rebalance(TreeNode** root)
{
	(*root)->bFactor = getHeight((*root)->right) - getHeight((*root)->left);
	if ((*root)->bFactor == 2)
	{
		TreeNode* desc = (*root)->right;
		if (desc->bFactor == 1)
			*root = leftRotation(*root);
		else
		{
			(*root)->right = rightRotation(desc);
			*root = leftRotation(*root);
		}
	}
	else
		if ((*root)->bFactor == -2)
		{
			TreeNode* desc = (*root)->left;
			if (desc->bFactor == 1)
				(*root)->left = leftRotation(desc);
			*root = rightRotation(*root);
		}
}
void upsert(TreeNode** root, Student* info)
{
	if (*root == NULL)
	{
		TreeNode* node = createTreeNode(info);
		*root = node;
	}
	else
	{
		if ((*root)->info->reference.intRef > info->reference.intRef)
			upsert(&(*root)->left, info);
		else if ((*root)->info->reference.intRef < info->reference.intRef)
			upsert(&(*root)->right, info);
		else
		{
			printf("Key already exists!");
			(*root)->info = info;
		}
	}
	rebalance(root);
}

void displayTreeStructure(TreeNode* root, int level)
{
	if (root != NULL)
	{
		for (int i = 0; i < level; i++)
			printf("\t");
		printf("%s - %d\n", root->info->name, root->info->reference.intRef);
		level++;
		displayTreeStructure(root->left, level);
		displayTreeStructure(root->right, level);
	}
	else
	{
		for (int i = 0; i < level; i++)
			printf("\t");
		printf("NULL\n");
	}
}
void deleteNodeByKey(TreeNode** root, unsigned char key)
{
	if (*root != NULL)
	{
		if ((*root)->info->reference.intRef > key)
			deleteNodeByKey(&(*root)->left, key);
		else if ((*root)->info->reference.intRef < key)
			deleteNodeByKey(&(*root)->right, key);
		else //we found the key
		{
			//the key is in a leaf
			if ((*root)->left == NULL && (*root)->right == NULL)
			{
				deleteStudent((*root)->info);
				free(*root);
				*root = NULL;
			}
			//the key is in a one descendent node
			else if((*root)->left == NULL)
			{
				deleteStudent((*root)->info);
				TreeNode* tmp = (*root);
				(*root) = (*root)->right;
				free(tmp);
			}
			else if ((*root)->right == NULL)
			{
				deleteStudent((*root)->info);
				TreeNode* tmp = (*root);
				(*root) = (*root)->left;
				free(tmp);

			}
			else
			{
				deleteFullNode(root, &(*root)->right);
			}
		}
	}
}

void deleteFullNode(TreeNode** root, TreeNode** rSubTree)
{
	if((*rSubTree)->left)
		deleteFullNode(root, &(*rSubTree)->left);
	else
	{
		//root - 65 // rSubTree - 78
		deleteStudent((*root)->info);
		(*root)->info = (*rSubTree)->info;
		TreeNode* tmp = *rSubTree;
		*rSubTree = tmp->right;
		free(tmp);
	}
}