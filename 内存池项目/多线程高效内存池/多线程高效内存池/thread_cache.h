#pragma once

#include"common.h"

class ThreadCache {
public:
	//�����ڴ���ͷ��ڴ�
	void* Alloc(size_t size);
	void Dealloc(void* ptr, size_t size);
	//�����Ļ����ȡ����
	void* FetchFromCentralCache(size_t index);
	//������������ж��󳬹�һ�����Ⱦ�Ҫ�ͷŸ����Ļ���
	void ListTooLong(FreeList& freelist, size_t num, size_t size);
private:
	FreeList _freelists[NFREE_LIST];
};
_declspec (thread) static ThreadCache* pThreaCache = nullptr;