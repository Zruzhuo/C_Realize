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

int main()
{
	testInsert();
	/*testShell();
	testSelect();*/
	system("pause");
	return 0;
}