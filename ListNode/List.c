#include"List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_next = NULL;
	newnode->_prev = NULL;
	newnode->_data = x;
	return newnode;
}
void ListInit(List* plt)
{
	assert(plt);
	plt->_head = NULL;
}

void ListDestory(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	ListNode* next = NULL;
	while (cur != head)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
}
void ListPushFront(List* plt, LTDataType x)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* first = head->_next;
	ListNode* newnode = BuyListNode(x);

	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = first;
	first->_prev = newnode;
}
void ListPushBack(List* plt, LTDataType x)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);

	head->_prev = newnode;
	newnode->_next = head;
	newnode->_prev = tail;
	tail->_next = newnode;
}
void ListPopFront(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	assert(head->_next != head);
	ListNode* first = head->_next;
	ListNode* second = first->_next;
	
	free(first);
	first = NULL;
	head->_next = second;
	second->_prev = head;
}
void ListPopBack(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	assert(head->_prev != head);
	ListNode* Onetail = head->_prev;
	ListNode* Twotail = Onetail->_prev;

	free(Onetail);
	Onetail = NULL;
	head->_prev = Twotail;
	Twotail->_next = head;
}
ListNode* ListFind(List* plt, LTDataType x)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;

	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	free(pos);
	pos = NULL;
	prev->_next = next;
	next->_prev = prev;
}
void ListRemove(List* plt, LTDataType x)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	ListNode* prev = cur->_prev;
	ListNode* next = cur->_next;
	while (cur != head)
	{
		if (cur->_data == x)
		{
			free(cur);
			prev->_next = next;
			next->_prev = prev;
			cur = next;
		}
		else
		{
			cur = cur->_next;
		}
	}
}

void ListPrint(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		printf("[%d]->", cur->_data);
		cur = cur->_next;
	}
}