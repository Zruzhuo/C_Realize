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

void SListInit(SList* psl, size_t capacity);//��ʼ��
void SListDestroy(SList* psl);//����
void CheckCapacity(SList* psl);//�������������ռ䣩

void SListPushFront(SList* psl, SLDataType x);//ͷ��
void SListPushBack(SList* psl, SLDataType x);//β��
void SListPopFront(SList* psl);//ͷɾ
void SListPopBack(SList* psl);//βɾ
size_t SListFind(SList* psl, SLDataType x);//����
void SListInsert(SList* psl, size_t pos, SLDataType x);//��pos�ڵ��ǰ�����x
void SListErase(SList* psl, size_t pos);//ɾ��pos�ڵ�
void SListRemove(SList* psl, SLDataType x);//ɾ��ֵΪx�Ľڵ�
void SListModify(SList* psl, size_t pos, SLDataType x);//�޸�pos�ڵ��ֵΪx
void SListPrint(SList* psl);//��ӡ˳���

void SListBubbleSort(SList* psl);//ð������
void SListBinaryFind(SList* psl, SLDataType x);//���ֲ���
void SListRemoveAll(SList* psl, SLDataType x);//ɾ������ֵΪx�Ľڵ�

