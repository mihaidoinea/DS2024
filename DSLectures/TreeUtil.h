#pragma once
#include "DataUtil.h"

typedef struct TreeN
{
	struct TreeN* left;
	Student* info;
	struct TreeN* right;
}TreeNode, *PTreeNode;

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
		printf("Student: %s\n", root->info->name);
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
			insertTree(&(*root)->left, info);
		else if ((*root)->info->reference.intRef < info->reference.intRef)
			insertTree(&(*root)->right, info);
		else
		{
			printf("Key already exists!");
			(*root)->info = info;
		}
	}
}