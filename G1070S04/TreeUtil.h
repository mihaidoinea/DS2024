#pragma once
#include "DataUtil.h"

typedef struct TreeN
{
	struct TreeN* left;
	Student* info;
	struct TreeN* right;
}TreeNode, * PTreeNode;

TreeNode* createTreeNode(Student* info)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->info = info;
	node->left = node->right = NULL;
	return node;
}
Student* getMax(TreeNode* root)
{
	while (root->right)
		root = root->right;
	return root->info;
}

void postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("Student: %s, reference: %d\n", root->info->name, root->info->reference.intRef);

	}
}

void inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);
		printf("Student: %s, reference: %d\n", root->info->name, root->info->reference.intRef);
		inorder(root->right);
	}
}

void preorder(TreeNode* root)
{
	if (root)
	{
		printf("Student: %s, reference: %d\n", root->info->name, root->info->reference.intRef);
		preorder(root->left);
		preorder(root->right);
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
			printf("Key already exists, updating it!");
			(*root)->info = info;
		}
	}
}
void DisplayTreeStructure(TreeNode* root, int level)
{
	if (root != NULL)
	{
		for (int i = 0; i < level; i++)
			printf("\t");
		printf("%s:%d\n", root->info->name, root->info->reference.intRef);
		level++;
		DisplayTreeStructure(root->left, level);
		DisplayTreeStructure(root->right, level);
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
		else //we have found the key
		{
			//the node is a leaf
			if ((*root)->left == NULL && (*root)->right == NULL)
			{
				deleteStudent((*root)->info);
				free(*root);
				*root = NULL;
			}
			else if ((*root)->left == NULL || (*root)->right == NULL)
			{
				TreeNode* tmp = *root;
				*root = (*root)->left ? (*root)->left : (*root)->right;
				deleteStudent(tmp->info);
				free(tmp);
			}
			else
			{
				//deleteFullNode(root, &(*root)->right);
			}
		}
	}
}

//void deleteFullNode(TreeNode** root, TreeNode** rSubTree)
//{
//	if ((*rSubTree)->left)
//		deleteFullNode(root, &(*rSubTree)->left);
//
//
//}
