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