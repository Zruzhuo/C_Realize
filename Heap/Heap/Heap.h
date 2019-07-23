#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<memory.h>

typedef int HPDateType;

typedef struct Heap
{
	HPDateType* _a;
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* hp, HPDateType* a, size_t n);//初始化
void HeapDestroy(Heap* hp);//销毁
void HeapPush(Heap* hp, HPDateType x);//插入一个数在数组的最后，然后进行向上调整
void HeapPop(Heap* hp);//删除数组里最小的数(即删除数组首元素，为了不破坏堆，只能首尾元素交换，然后size--，最后向下调整)
HPDateType HeapTop(Heap* hp);//获取数组首元素
size_t HeapSize(HPDateType* a);//计算堆的元素个数
void HeapSort(Heap* hp);//查找
void AdjustDown(HPDateType* a, size_t n, size_t );//向下调整
void AdjustUp(HPDateType* a, size_t child);//向上调整
void HeapPrint(Heap* hp);