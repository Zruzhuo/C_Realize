#pragma once

#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;

typedef struct BTNode
{
	BTDataType val;
	struct BTNode* _left;
	struct BTNode* _right;
}BTNode;

void BTInit(BTNode* root);
void BTDistory(BTNode* root);
int BTLeafSize(BTNode* root);
int BTLevelKSize(BTNode* root, int k);
BTNode* BTFind(BTNode* root, char x);

void BTPrevOrder(BTNode* root); //二叉树的前序遍历
void BTInOrder(BTNode* root); //二叉树的中序遍历
void BTPostOrder(BTNode* root); //二叉树的后序遍历