#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode 
{
	struct ListNode* _prev;
	struct ListNode* _next;
	LTDataType _data;
}ListNode;

typedef struct List 
{
	ListNode* _head;
}List;

void ListInit(List* plt);
void ListDestory(List* plt);
ListNode* BuyListNode(LTDataType x);
void ListPushFront(List* plt, LTDataType x);
void ListPushBack(List* plt, LTDataType x);
void ListPopFront(List* plt);
void ListPopBack(List* plt);
ListNode* ListFind(List* plt, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
void ListRemove(List* plt, LTDataType x);
void ListPrint(List* plt);
