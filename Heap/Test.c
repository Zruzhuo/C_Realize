#include<stdio.h>

typedef int HPDateType;

typedef struct Heap
{
	HPDateType* _a;
	size_t _size;
	size_t _capcity;
}Heap;

void HeapInit(Heap* hp, HPDateType* a, size_t n)
{
	assert(hp && a);
	hp->_a = (HPDateType*)malloc(sizeof(HPDateType) * n);
	memcpy(hp->_a, a, sizeof(HPDateType) * n);
	hp->_size = n;
	hp->_capcity = n;
}
void 