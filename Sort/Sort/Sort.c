#include"Sort.h"

void Swap(int* p1, int* p2)
{
	int temp = 0;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void InsertSort(int* a, int n)//插入排序
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
void ShellSort(int* a, int n)//希尔排序
{
	//间距为gap的排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)//预排序
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
void SelectSort(int* a, int n)//选择排序
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
void  AdjustDown(int* a, int n, int parent)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)
	{
		if ((child + 1) < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
void BubbleSort(int* a, int n)
{
	int end = n - 1;
	while (end--)
	{
		for (int i = 0; i < end; ++i)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
			}
		}
	}
	
}
int GetMidIndex(int* a, int left, int right)//三数取中法
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}

	}
}
int PartSort1(int* a, int left, int right)//快速排序->左右指针法
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = a[left];
	int key_index = left;
	while (left < right)
	{
		//left找比key打的，right找比key小的，再交换
		while (left < right && a[right] >= key)//先检查是否越界，然后再访问
		{
			--right;
		}
		while (left < right && a[left] <= key)
		{
			++left;
		}
		Swap(&a[left], &a[right]);
		if (left < right)
		{			
			++left;
			--right;
		}	
	}
	Swap(&a[left], &a[key_index]);
	return left;
}
void QuickSort1(int* a, int left, int right)//快速排序->左右指针法
{
	if (left >= right)
		return;
	if (right - left + 1 > 10)
	{
		int key_index = PartSort1(a, left, right);
		//分成[left,key_index - 1] key [key_index + 1,right]
		QuickSort1(a, left, key_index - 1);
		QuickSort1(a, key_index + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}

int PartSort2(int* a, int left, int right)//快速排序->挖坑法
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[right] = a[left];
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[left] = a[right];
		
	}
	a[right] = key;
	return right;
}
void QuickSort2(int* a, int left, int right)//快速排序->挖坑法
{
	if (left >= right)
		return;
	if (right - left + 1 > 10)
	{
		int key_index = PartSort2(a, left, right);
		QuickSort2(a, left, key_index - 1);
		QuickSort2(a, key_index + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
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