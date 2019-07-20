#include"SList.h"

void test1()
{
	SList sl;
	SListInit(&sl, 1);
	SListPushFront(&sl, 3);
	SListPushFront(&sl, 3);
	SListPushFront(&sl, 6);
	SListPushFront(&sl, 3);
	SListPushFront(&sl, 1);
	SListPushFront(&sl, 9);
	SListPushBack(&sl, 9);
	SListPopFront(&sl);
	SListPopBack(&sl);
	SListPrint(&sl);

	printf("%d\n",SListFind(&sl, 6));

	SListInsert(&sl, 3, 11);
	SListPrint(&sl);

	SListErase(&sl, 3);
	SListPrint(&sl);

	SListRemove(&sl, 3);
	SListPrint(&sl);

	SListRemoveAll(&sl, 3);
	SListPrint(&sl);

	SListBubbleSort(&sl);
	SListPrint(&sl);

	SListBinaryFind(&sl, 11);

	SListDestroy(&sl);
}

int main()
{
	test1();
	system("pause");
	return 0;
}