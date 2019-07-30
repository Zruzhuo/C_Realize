#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SListDataType;
typedef struct SListNode//ÿ���ڵ���һ���ṹ��
{
	SListDataType _data;//������
	struct SListNode* _next;//ָ����
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void  SListInit(SList* pcb);
void SListDestroy(SList* pcb);

void  SListPushFront(SList* pcb, SListDataType x);//ͷ��
void  SListPushBack(SList* pcb, SListDataType x);//β��

void  SListPopFront(SList* pcb);//ͷɾ
void  SListPopBack(SList* pcb);//βɾ


SListNode* SListFind(SList* pcb, SListDataType x);//����

void SListInsertAfter(SListNode* pos, SListDataType x);//��POS�ĺ�����в���
void SListEraseAfter(SListNode* pos);//��pos�������һ��ɾ��

void SListInsertFront(SList* pcb, SListNode* pos, SListDataType x);//��pos��ǰ����в���

void SListRemove(SList* pcb, SListDataType x);//�ҳ�һ���������ظ����ݵĵ�һ������ɾ��
void SListAllRemove(SList* pcb, SListDataType x);//ɾ���� X ��ͬ����������
void SListPrint(SList* pcb);//��ӡ