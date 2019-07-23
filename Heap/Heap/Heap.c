#include"Heap.h"

void Swap(HPDateType* p1, HPDateType* p2)
{
	HPDateType temp = 0;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void HeapInit(Heap* hp, HPDateType* a, size_t n)
{
	assert(hp);
	hp->_a = (HPDateType*)malloc(sizeof(HPDateType) * n);
	memcpy(hp->_a, a, sizeof(HPDateType) * n);
	hp->_size = n;
	hp->_capacity = n;
	for (size_t i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
void AdjustUp(HPDateType* a, size_t child)
{
	//µÝ¹é
	/*assert(a);
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
	AdjustUp(a, child);*/
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
void  AdjustDown(HPDateType* a, size_t n, size_t parent)
{
	assert(a);
	size_t child = parent * 2 + 1;
	while (child < n)
	{
		if ((child + 1) > n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[parent] > a[child])
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
void HeapPush(Heap* hp, HPDateType x)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		size_t newcapacity = hp->_capacity == 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HPDateType*)realloc(hp->_a, sizeof(HPDateType) * newcapacity);
		if (hp->_a == NULL)
		{
			printf("realloc error\n");
			exit(-1);
		}
		hp->_capacity = newcapacity;
	}
	hp->_size++;
	hp->_a[hp->_size - 1] = x;
	AdjustUp(hp->_a, hp->_size - 1);
}
void HeapPop(Heap* hp)
{
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;

	AdjustDown(hp->_a, hp->_size, 0); 
}

HPDateType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
size_t HeapSize(HPDateType* a)
{
	assert(a);
	size_t count = 0;
	while (&a[count] == NULL)
	{
		count++;
	}
	return count;
}

void HeapSort(Heap* hp)
{
	assert(hp);
	size_t i = hp->_size - 1;
	while (i)
	{
		Swap(&hp->_a[0], &hp->_a[i]);
		i--;
		AdjustDown(hp->_a, i, 0);
	}
}
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (size_t i = 0; i < hp->_size; i++)
	{
		printf("%d->", hp->_a[i]);
	}
	printf("\n");
}