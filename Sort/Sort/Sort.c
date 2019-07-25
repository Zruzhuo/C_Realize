#include"Sort.h"

void Swap(int* p1, int* p2)
{

}
void InsertSort(int* a, int n)//²åÈëÅÅÐò
{

}
void ShellSort(int* a, int n)//Ï£¶ûÅÅÐò
{
	//¼ä¾àÎªgapµÄÅÅÐò
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)//Ô¤ÅÅÐò
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void SelectSort(int* a, int n)//Ñ¡ÔñÅÅÐò
{
	int begin = 0;
	int end = n - 1;
	int	min_index;
	int max_index;
	while (begin <= end)
	{
		min_index = max_index = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] < a[min_index])
			{
				min_index = i;
			}
			if (a[i] > a[max_index])
			{
				max_index = i;
			}
		}
		Swap(&a[begin], &a[min_index]);
		if (max_index == begin)
		{
			max_index = min_index;
		}
		Swap(&a[end], &a[max_index]);

		++begin;
		--end;
	}
}
void PrintArr(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d->", a[i]);
	}
	printf("\n");
}