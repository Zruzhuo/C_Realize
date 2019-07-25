#include"Sort.h"

void Swap(int* p1, int* p2)
{
	int temp = 0;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void InsertSort(int* a, int n)//≤Â»Î≈≈–Ú
{
	int i = 0;
	int j = 0;
	int cur = 0;
	for (i = 1; i < n; ++i)
	{
		cur = a[i];
		j = i - 1;	
		for (; j >= 0 && cur < a[j]; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = cur;
	}
}
void ShellSort(int* a, int n)//œ£∂˚≈≈–Ú
{
	//º‰æ‡Œ™gapµƒ≈≈–Ú
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)//‘§≈≈–Ú
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
void SelectSort(int* a, int n)//—°‘Ò≈≈–Ú
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