#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_tail = NULL;
}

QueueNode* BuyQueueNode(QDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);
	if (pq->_tail == NULL)
	{
		pq->_front = pq->_tail = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq && pq->_front);
	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
	if (pq->_front == NULL)
	{
		pq->_tail = NULL;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq && pq->_front);
	return pq->_front->_data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq && pq->_tail);
	return pq->_tail->_data;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL;
}

size_t QueueSize(Queue* pq)
{
	assert(pq);
	size_t s = 0;
	QueueNode* cur = pq->_front;
	while (cur)
	{
		++s;
		cur = cur->_next;
	}
	return s;
}