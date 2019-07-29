#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


void InsertSort(int* a, int n);//插入排序
void ShellSort(int* a, int n);//希尔排序
void SelectSort(int* a, int n);//选择排序
void HeapSort(int* a, int n);//堆排序
void BubbleSort(int* a, int n);//冒泡排序
void QuickSort1(int* a, int left, int right);//快速排序->左右指针法
void QuickSort2(int* a, int left, int right);//快速排序->挖坑法
void QuickSort3(int* a, int left, int right);//快速排序->前后指针法
//void QuickSortNoR(int* a, int left, int right);//快速排序->非递归
void MergeSort(int* a, int n);//归并排序
void MergeSortNoR(int* a, int n);//归并排序->非递归
void CountSort(int* a, int n);//非比较排序->计数排序
void PrintArr(int* a, int n);//打印






//当数组有序时进行排序，插入排序是最快的，而选择排序最慢
//快速排序在数组有序时排序，有很大的缺陷，所以使用三数取中法进行优化
//希尔排序、堆排序、快速排序适合数据量大的排序