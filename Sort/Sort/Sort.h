#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


void InsertSort(int* a, int n);//��������
void ShellSort(int* a, int n);//ϣ������
void SelectSort(int* a, int n);//ѡ������
void HeapSort(int* a, int n);//������
void BubbleSort(int* a, int n);//ð������
void QuickSort1(int* a, int left, int right);//��������->����ָ�뷨
void QuickSort2(int* a, int left, int right);//��������->�ڿӷ�
void QuickSort3(int* a, int left, int right);//��������->ǰ��ָ�뷨
//void QuickSortNoR(int* a, int left, int right);//��������->�ǵݹ�
void MergeSort(int* a, int n);//�鲢����
void MergeSortNoR(int* a, int n);//�鲢����->�ǵݹ�
void CountSort(int* a, int n);//�ǱȽ�����->��������
void PrintArr(int* a, int n);//��ӡ






//����������ʱ�������򣬲������������ģ���ѡ����������
//������������������ʱ�����кܴ��ȱ�ݣ�����ʹ������ȡ�з������Ż�
//ϣ�����򡢶����򡢿��������ʺ��������������