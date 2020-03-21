#pragma once

#include"common.h"

class ThreadCache {
public:
	void* Alloc(size_t size);
	void Dealloc(void* ptr, size_t size);
private:
	FreeList _freelists[NFREE_LIST];
};