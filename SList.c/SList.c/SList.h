#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int SLDataType;

typedef struct SList
{
	SLDataType* _array;
	size_t _size;
	size_t _capacity;
}SList;

void SListInit(SList* psl, size_t capacity);//初始化
void SListDestroy(SList* psl);//销毁
void CheckCapacity(SList* psl);//增加容量（开空间）

void SListPushFront(SList* psl, SLDataType x);//头插
void SListPushBack(SList* psl, SLDataType x);//尾插
void SListPopFront(SList* psl);//头删
void SListPopBack(SList* psl);//尾删
size_t SListFind(SList* psl, SLDataType x);//查找
void SListInsert(SList* psl, size_t pos, SLDataType x);//在pos节点的前面插入x
void SListErase(SList* psl, size_t pos);//删除pos节点
void SListRemove(SList* psl, SLDataType x);//删除值为x的节点
void SListModify(SList* psl, size_t pos, SLDataType x);//修改pos节点的值为x
void SListPrint(SList* psl);//打印顺序表

void SListBubbleSort(SList* psl);//冒泡排序
void SListBinaryFind(SList* psl, SLDataType x);//二分查找
void SListRemoveAll(SList* psl, SLDataType x);//删除所有值为x的节点

