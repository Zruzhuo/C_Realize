#include"Heap.h"

void HeapInit(Heap* hp, HPDateType* a, size_t n)
{
	assert(hp && a);
	hp->_a = (HPDateType*)malloc(sizeof(HPDateType) * n);
	memcpy(hp->_a, a, sizeof(HPDateType) * n);
	hp->_size = n;
	hp->_capcity = n;
}
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capcity = hp->_size = 0;
}
void AdjustUp(HPDateType* a, size_t child)
{
	//µÝ¹é
	assert(a);
	size_t parent = (child - 1) / 2;
	if (a[child] > a[parent])
	{
		Swap(&a[child], &a[parent]);
	}
	child = parent;
	if (child == 0)
	{
		return;
	}
	parent = (parent - 1) / 2;
	AdjustUp(a, child);
	//·ÇµÝ¹é
	assert(a);
	size_t parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(Heap* hp)
{
	assert(hp->_size > 0);
	Swap(hp->_a[0], hp->_a[hp->_size - 1]);
	hp->_size--;

	AdjustDown(hp->_a, hp->_size, 0); 
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
}
void TestHeap()
{
	int a[] = { 7, 2, 1, 8, 0 };

}