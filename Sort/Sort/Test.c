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
	int a3[11] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int a4[20] = { 3, 3, 3, 7, 2 ,7, 7, 7, 7, 44, 2, 22, 33, 11, 83,1 , 2};
	PrintArr(a3, 10);
	/*QuickSort1(a3, 0, 9);
	PrintArr(a3, 10);*/
	QuickSort2(a4, 0, 16);
	PrintArr(a4, 17);
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
void testMerge()
{
	int a4[6] = { 3, 2, 4, 1, 5 };
	PrintArr(a4, 5);
	MergeSortNoR(a4, 5);
	PrintArr(a4, 5);
	printf("\n");
}
void testCount()
{
	int a4[6] = { 3, 2, 4, 1, 5 };
	PrintArr(a4, 5);
	CountSort(a4, 5);
	PrintArr(a4, 5);
	printf("\n");
}
int main()
{
	/*testInsert();
	testShell();
	testSelect();
	testBubble();*/
	/*testQuick();*/
	//testHeap();
	//testMerge();
	testCount();
	system("pause");
	return 0;
}