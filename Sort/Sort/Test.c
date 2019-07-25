#include"Sort.h"

int main()
{
	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	ShellSort(a, 10);
	PrintArr(a, 10);
	system("pause");
	return 0;
}