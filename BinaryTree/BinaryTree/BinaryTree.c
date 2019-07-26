#include"BinaryTree.h"

int BinaryTreeLeafSize(BTNode* root)
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
int BinaryTreeLevelKSize(BTNode* root, int k)
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
BTNode* BinaryTreeFind(BTNode* root, char x)
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