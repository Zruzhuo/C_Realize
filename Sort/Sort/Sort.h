#pragma once

#include<stdio.h>

void ShellSort(int* a, int n);
void PrintArr(int* a, int n);






//当数组有序时进行排序，插入排序是最快的，而选择排序最慢
//数组无序，且数据量大时，希尔排序最好