#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<stdbool.h>

typedef int STDateType;
typedef struct Stack
{
	STDateType* _array;//Êý×é
	size_t _top;//Õ»¶¥
	size_t capcity;//ÈÝÁ¿
}Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);
void StackPush(Stack* ps, STDateType x);
void StackPop(Stack* ps);
STDateType StackTop(Stack* ps);
size_t StackSize(Stack* ps);
bool StackEmpty(Stack* ps);