#include"SListNode.h"
void Test()
{
	SList  cb;
	SListInit(&cb);
	SListPushBack(&cb, 1);
	SListPushBack(&cb, 2);
	SListPushBack(&cb, 2);
	SListPushBack(&cb, 3);
	SListPushBack(&cb, 4);
	SListPushBack(&cb, 5);

	SListPopBack(&cb);
	SListPushFront(&cb, 2);
	SListPopFront(&cb);
	SListPrint(&cb);

	SListNode* pos = SListFind(&cb, 1);
	SListInsertAfter(pos, 25);

	SListNode* pos1 = SListFind(&cb, 3);
	SListInsertAfter(pos1, 25);

	SListEraseAfter(pos);

	SListRemove(&cb, 2);

	SListNode* pos3 = SListFind(&cb, 3);
	SListInsertFront(&cb, pos3, 55);

	SListAllRemove(&cb, 2);

	SListPrint(&cb);
}
int main()
{
	Test();
	system("pause");
	return 0;
}
