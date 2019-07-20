#include"SList.h"

void Swap(SLDataType* p1, SLDataType* p2)
{
	assert(p1 && p2);
	SLDataType temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void SListInit(SList* psl, size_t capacity)
{
	assert(psl);
	psl->_array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	if (psl->_array == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
	psl->_capacity = capacity;
	psl->_size = 0;
}
void SListDestroy(SList* psl)
{
	assert(psl);
	free(psl->_array);
	psl->_array = NULL;
}
void CheckCapacity(SList* psl)
{
	assert(psl);
	size_t newcapacity = (psl->_capacity) * 2;
	if (psl->_size < psl->_capacity)
	{
		return;
	}
	else if (psl->_capacity == psl->_size)
	{
		SLDataType* newarray = (SLDataType*)realloc(psl->_array, sizeof(SLDataType)*newcapacity);
		if (newarray == NULL)
		{
			printf("realloc error");
		}
		psl->_array = newarray;
		psl->_capacity = newcapacity;
	}
}
void SListPushFront(SList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->_size += 1;
	for (size_t i = psl->_size - 1; i > 0; --i)
	{
		psl->_array[i] = psl->_array[i - 1];
	}
	psl->_array[0] = x;
}
void SListPushBack(SList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->_size += 1;
	psl->_array[psl->_size - 1] = x;
}
void SListPopFront(SList* psl)
{
	assert(psl && psl->_size > 0);
	for (size_t i = 0; i <= psl->_size - 1; i++)
	{
		psl->_array[i] = psl->_array[i + 1];
	}
	psl->_size--;
}
void SListPopBack(SList* psl)
{
	assert(psl && psl->_size > 0);
	psl->_size--;
}
size_t SListFind(SList* psl, SLDataType x)
{
	assert(psl);
	size_t input = psl->_size;
	while (input)
	{
		if (psl->_array[input - 1] == x)
		{
			return input - 1;
		}
		input--;
	}
}
void SListInsert(SList* psl, size_t pos, SLDataType x)
{
	assert(psl->_size > 0);
	CheckCapacity(psl);
	psl->_size += 1;
	for (size_t i = psl->_size - 1; i >= pos; --i)
	{
		psl->_array[i] = psl->_array[i - 1];
	}
	psl->_array[pos] = x;
}
void SListErase(SList* psl, size_t pos)
{
	assert(psl->_size > 0);
	for (size_t i = pos; i < psl->_size - 1; i++)
	{
		psl->_array[i] = psl->_array[i + 1];
	}
	psl->_size--;
}
void SListRemove(SList* psl, SLDataType x)
{
	assert(psl->_size > 0);
	for (size_t i = 0; i < psl->_size; i++)
	{
		if (psl->_array[i] == x)
		{
			SListErase(psl, i);
			return;
		}
	}
}
void SListModify(SList* psl, size_t pos, SLDataType x)
{
	assert(psl->_size > 0);
	psl->_array[pos] = x;
}
void SListPrint(SList* psl)
{
	assert(psl);
	for (size_t i = 0; i < psl->_size; i++)
	{
		printf("%d->", psl->_array[i]);
	}
	printf("\n");
}
void SListBubbleSort(SList* psl)
{
	assert(psl);
	for (size_t i = 0; i <= psl->_size - 1; i++)
	{
		size_t flag = 0;
		for (size_t j = 0; j < psl->_size - 1 - i; j++)
		{
			if (psl->_array[j] > psl->_array[j + 1])
			{
				Swap(&(psl->_array[j]), &(psl->_array[j + 1]));
				flag++;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
void SListBinaryFind(SList* psl, SLDataType x)
{
	assert(psl);
	SListBubbleSort(psl);
	size_t left = 0;
	size_t right = psl->_size - 1;
	size_t flag = 0;
	while (left <= right)
	{
		size_t middle = left + (right - left) / 2;
		if (psl->_array[middle] == x)
		{
			flag = 1;
			printf("找到了，下标为%d\n", middle);
			break;
		}
		else if(x < psl->_array[middle])
		{
			right = middle + 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	if (flag == 0)
	{
		printf("找不到\n");
	}
}
void SListRemoveAll(SList* psl, SLDataType x)
{
	assert(psl);
	for (size_t i = 0; i < psl->_size; i++)
	{
		if (psl->_array[i] == x)
		{
			SListErase(psl, i);
		}
	}
}