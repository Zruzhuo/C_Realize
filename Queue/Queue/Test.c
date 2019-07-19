#include"Queue.h"

void test1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePop(&q);
	size_t s = QueueSize(&q);
	while (s)
	{
		printf("%d->", QueueFront(&q));
		QueuePop(&q);
		--s;
	}
	printf("\n");
	/*printf("%d\n", QueueBack(&q));
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueSize(&q));*/
	system("pause");
	QueueDestroy(&q);
}
int main()
{
	test1();
	return 0;
}