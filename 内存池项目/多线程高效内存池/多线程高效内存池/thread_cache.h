#pragma once

#include"common.h"

class ThreadCache {
public:
	//申请内存和释放内存
	void* Alloc(size_t size);
	void Dealloc(void* ptr, size_t size);
	//从中心缓存获取对象
	void* FetchFromCentralCache(size_t index);
	//如果自由链表中对象超过一定长度就要释放给中心缓存
	void ListTooLong(FreeList& freelist, size_t num, size_t size);
private:
	FreeList _freelists[NFREE_LIST];
};
_declspec (thread) static ThreadCache* pThreaCache = nullptr;