#include"BinaryTree.h"

void BTInit(BTNode* root)
{
	assert(root);
	root->_left = NULL;
	root->_right = NULL;
}
void BTDistory(BTNode* root)
{
	if (root == NULL)
		return;
	BTDistory(root->_left);
	BTDistory(root->_right);
	free(root);
	root = NULL;
	return;
}
int BTLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
int BTLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
BTNode* BTFind(BTNode* root, char x)
{
	if (root == NULL)
		return NULL;

	if (root->val == x)
		return root;

	BTNode* lret = BinaryTreeFind(root->_left, x);
	if (lret != NULL)
	{
		return lret;
	}

	BTNode* rret = BinaryTreeFind(root->_right, x);
	if(rret != NULL)
	{
		return rret;
	}

	return NULL;
}

void BTPrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->val);
	BTPrevOrder(root->_left);
	BTPrevOrder(root->_right);
}
void BTInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BTPrevOrder(root->_left);
	printf("%c ", root->val);
	BTPrevOrder(root->_right);
}
void BTPostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BTPrevOrder(root->_left);
	BTPrevOrder(root->_right);
	printf("%c ", root->val);
}