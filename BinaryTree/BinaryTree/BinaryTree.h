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

void BTPrevOrder(BTNode* root); //��������ǰ�����
void BTInOrder(BTNode* root); //���������������
void BTPostOrder(BTNode* root); //�������ĺ������