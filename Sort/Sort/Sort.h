#pragma once

#include<stdio.h>

void InsertSort(int* a, int n);//插入排序
void ShellSort(int* a, int n);//希尔排序
void SelectSort(int* a, int n);//选择排序
void PrintArr(int* a, int n);






//当数组有序时进行排序，插入排序是最快的，而选择排序最慢
//数组无序，且数据量大时，希尔排序最好