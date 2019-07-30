#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SListDataType;
typedef struct SListNode//每个节点是一个结构体
{
	SListDataType _data;//数据域
	struct SListNode* _next;//指针域
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void  SListInit(SList* pcb);
void SListDestroy(SList* pcb);

void  SListPushFront(SList* pcb, SListDataType x);//头插
void  SListPushBack(SList* pcb, SListDataType x);//尾插

void  SListPopFront(SList* pcb);//头删
void  SListPopBack(SList* pcb);//尾删


SListNode* SListFind(SList* pcb, SListDataType x);//查找

void SListInsertAfter(SListNode* pos, SListDataType x);//在POS的后面进行插入
void SListEraseAfter(SListNode* pos);//把pos后面的那一个删除

void SListInsertFront(SList* pcb, SListNode* pos, SListDataType x);//在pos的前面进行插入

void SListRemove(SList* pcb, SListDataType x);//找出一组数据中重复数据的第一个进行删除
void SListAllRemove(SList* pcb, SListDataType x);//删除与 X 相同的所有数据
void SListPrint(SList* pcb);//打印