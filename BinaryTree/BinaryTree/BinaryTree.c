

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
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
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, char x)
{
	if (root == NULL)
		return NULL;

	if (root->val == x)
		return root;

	BTNode* lret = BinaryTreeFind(root->left, x);
	if (lret != NULL)
	{
		return lret;
	}

	BTNode* rret = BinaryTreeFind(root->right, x);
	if(rret != NULL)
	{
		return rret;
	}

	return NULL;
}