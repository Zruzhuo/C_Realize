#include"SList.h"

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
		for (size_t i = 0; i < psl->_size; i++)
		{
			newarray[i] = psl->_array[i];
		}
		psl->_array = newarray;
		psl->_capacity = newcapacity;
	}
}