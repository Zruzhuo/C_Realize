#include"Sort.h"

void testInsert()
{
	int a1[6] = { 3, 2, 4, 1, 5 };
	PrintArr(a1, 5);
	InsertSort(a1, 5);
	PrintArr(a1, 5);
	printf("\n");
}
void testShell()
{
	int a2[6] = { 3, 2, 4, 1, 5 };
	PrintArr(a2, 5);
	ShellSort(a2, 5);
	PrintArr(a2, 5);
	printf("\n");
}
void testSelect()
{
	int a3[6] = { 3, 2, 4, 1, 5 };
	PrintArr(a3, 5);
	SelectSort(a3, 5);
	PrintArr(a3, 5);
	printf("\n");
}

void testBubble()
{
	int a3[6] = { 3, 2, 4, 1, 5 };
	PrintArr(a3, 5);
	BubbleSort(a3, 5);
	PrintArr(a3, 5);
	printf("\n");
}
void testQuick()
{
	int a3[7] = { 3, 2, 77, 11, 2 ,71};
	int a4[15] = { 3, 2, 77, 11, 2 ,71, 11, 22, 33, 44, 2, 22};
	PrintArr(a3, 6);
	QuickSort1(a3, 0, 5);
	PrintArr(a3, 6);
	QuickSort2(a4, 0, 11);
	PrintArr(a4, 12);
	printf("\n");
}
void testHeap()
{
	int a3[6] = { 3, 2, 4, 1, 5 };
	PrintArr(a3, 5);
	HeapSort(a3, 5);
	PrintArr(a3, 5);
	printf("\n");
}
int main()
{
	testInsert();
	testShell();
	testSelect();
	testBubble();
	testQuick();
	testHeap();
	system("pause");
	return 0;
}