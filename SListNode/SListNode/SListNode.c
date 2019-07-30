#include"SListNode.h"

void  SListInit(SList* pcb)
{
	assert(pcb);
	pcb->_head = NULL;
}
void SListDestroy(SList* pcb)
{
	assert(pcb);
	SListNode* cur = pcb->_head;
	SListNode* next = NULL;
	while (cur != NULL)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
}
void  SListPushBack(SList* pcb, SListDataType x)
{
	assert(pcb);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
	newnode->_data = x;
	newnode->_next = NULL;

	if (pcb->_head == NULL)//为空时
	{
		pcb->_head = newnode;
	}
	else//非空时
	{
		SListNode* cur = pcb->_head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}
void  SListPopBack(SList* pcb)
{
	assert(pcb);
	SListNode* cur = pcb->_head;
	if (cur == NULL)//没有节点时
	{
		return;
	}
	else if (cur->_next == NULL)
	{
		free(cur);
		pcb->_head = NULL;
	}
	else
	{
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}
}
void  SListPushFront(SList* pcb, SListDataType x)
{
	assert(pcb);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	{
		if (newnode == NULL)
		{
			printf("newnode error");
			exit(-1);
		}
		newnode->_data = x;
		newnode->_next = NULL;

		newnode->_next = pcb->_head;
		pcb->_head = newnode;
	}
}
void  SListPopFront(SList* pcb)
{
	assert(pcb);
	SListNode* cur = pcb->_head;
	if (cur == NULL)
	{
		return;
	}
	else
	{
		pcb->_head = cur->_next;
		free(cur);
		cur = NULL;
	}
}

SListNode* SListFind(SList* pcb, SListDataType x)
{
	assert(pcb);
	SListNode* cur = pcb->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_next = pos->_next;
	pos->_next = newnode;
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->_next == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = pos->_next;
		pos->_next = next->_next;
		free(next);
		next = NULL;
	}
}
void SListInsertFront(SList* pcb, SListNode* pos, SListDataType x)
{
	assert(pcb);
	assert(pos);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	SListNode* cur = pcb->_head;
	SListNode* pcur = NULL;
	while (cur != NULL)
	{
		if (cur->_data == pos->_data)
		{
			if (pcur == NULL)
			{
				pcb->_head = newnode;
				newnode->_next = cur;
			}
			else
			{
				pcur->_next = newnode;
				newnode->_next = cur;
			}
			return;
		}
		else
		{
			pcur = cur;
			cur = cur->_next;
		}
	}
}

void SListRemove(SList* pcb, SListDataType x)
{
	assert(pcb);
	SListNode* cur = pcb->_head;
	SListNode* pcur = NULL;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			if (pcur == NULL)
				pcb->_head = cur->_next;
			else
				pcur->_next = cur->_next;
			free(cur);
			cur = NULL;
			return;
		}
		else
		{
			pcur = cur;
			cur = cur->_next;
		}
	}
}
void SListAllRemove(SList* pcb, SListDataType x)
{
	assert(pcb);
	SListNode* cur = pcb->_head;
	SListNode* prev = NULL;
	SListNode* next = NULL;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			next = cur->_next;
			free(cur);
			cur = NULL;
			cur = next;
			if (prev == NULL)
			{
				pcb->_head = next;
			}
			else
			{
				prev->_next = cur;
			}
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}
void SListPrint(SList* pcb)
{
	assert(pcb);
	SListNode* cur = pcb->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}