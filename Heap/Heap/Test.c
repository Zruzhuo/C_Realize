#include"Heap.h"

void test()
{
	Heap h;
	HPDateType a[] = {0,1,2};
	HeapInit(&h, a, sizeof(a)/sizeof(a[0]));
	HeapPush(&h, 1);
	HeapPrint(&h);
	HeapDestroy(&h);
}

int main()
{
	test();
	system("pause");
	return 0;
}
