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

void HeapInit(Heap* hp, HPDateType* a, size_t n);//��ʼ��
void HeapDestroy(Heap* hp);//����
void HeapPush(Heap* hp, HPDateType x);//����һ��������������Ȼ��������ϵ���
void HeapPop(Heap* hp);//ɾ����������С����(��ɾ��������Ԫ�أ�Ϊ�˲��ƻ��ѣ�ֻ����βԪ�ؽ�����Ȼ��size--��������µ���)
HPDateType HeapTop(Heap* hp);//��ȡ������Ԫ��
size_t HeapSize(HPDateType* a);//����ѵ�Ԫ�ظ���
void HeapSort(Heap* hp);//����
void AdjustDown(HPDateType* a, size_t n, size_t );//���µ���
void AdjustUp(HPDateType* a, size_t child);//���ϵ���
void HeapPrint(Heap* hp);