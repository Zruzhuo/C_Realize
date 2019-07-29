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
int PartSort3(int* a, int left, int right)//快速排序->前后指针法
{
	int prev = left - 1;
	int cur = left;
	int key = a[right];
	while(cur != right)
	{
		if (a[cur] <= key && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}		
		++cur;		
	}
	++prev;
	Swap(&a[right], &a[prev]);
	return prev;
}
void QuickSort3(int* a, int left, int right)//快速排序->前后指针法
{
	if (left >= right)
		return;
	if (right - left + 1 > 10)
	{
		int key_index = PartSort3(a, left, right);
		QuickSort3(a, left, key_index - 1);
		QuickSort3(a, key_index + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}
//void QuickSortNoR(int* a, int left, int right)//快速排序->非递归
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, left);
//	StackPush(&s, right);
//	while (!StackEmpty(&s))
//	{
//		int end = StackTop(&s);
//		StackPop(&s);
//		int begin = StackTop(&s);
//		StackPop(&s);
//		int key_index = PartSort3(a, begin, end);
//		if (begin < key_index - 1)
//		{
//			StackPush(&s, begin);
//			StackPush(&s, key_index - 1);
//		}
//		if  (key_index + 1 < end)
//		{		
//			StackPush(&s, key_index + 1);
//			StackPush(&s, end);
//		}
//	}
//}
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left == right)
		return;

	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1];
			++begin1;
		}
		else
		{
			tmp[i++] = a[begin2];
			++begin2;
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1];
		++begin1;
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2];
		++begin2;
	}
	memcpy(a + left, tmp + left, sizeof(int)*(i - left));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
void MergeSortNoR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{		
		for (int begin = 0; begin < n; begin += 2*gap)
		{
			//[begin, begin + gap - 1] [begin + gap, begin + 2*gap - 1]
			//[0, 0][1, 1]  gap = 1
			//[0, 1][2, 3]  gap = 2	
			int begin1 = begin, begin2 = begin + gap, end1 = begin + gap - 1, end2 = begin + 2*gap -1;
			if (end1 >= n)
				end1 = n - 1;
			if (end2 >= n)
				end2 = n - 1;
			int index = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
					tmp[index++] = a[begin1++];
				else
					tmp[index++] = a[begin2++];
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}
		}
		memcpy(a, tmp, sizeof(int) * n);
		gap *= 2;
	}
	free(tmp);
}

void CountSort(int* a, int n)//非比较排序->计数排序
{
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (max < a[i])
		{
			max = a[i];
		}
		if (min > a[i])
		{
			min = a[i];
		}
	}
	int size = max - min + 1;
	int* tmp = (int*)malloc(sizeof(int) * size);
	memset(tmp, 0, sizeof(int) * size);
	//统计次数
	for (int i = 0; i < n; ++i)
	{
		tmp[a[i] - min]++;
	}
	//排序
	int j = 0;
	for (int i = 0; i < size; ++i)
	{
		while (tmp[i]--)
		{
			a[j++] = i + min;
		}
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