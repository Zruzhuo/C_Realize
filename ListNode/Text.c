#include"List.h"

int main()
{
	List s;
	ListInit(&s);
	ListPushBack(&s, 1);
	ListPushBack(&s, 2);
	ListPushBack(&s, 3);
	ListPushFront(&s, 3);
	ListPushFront(&s, 3);
	ListPushFront(&s, 9);
	ListRemove(&s, 3);
	ListPrint(&s);
	system("pause");
	return 0;
}