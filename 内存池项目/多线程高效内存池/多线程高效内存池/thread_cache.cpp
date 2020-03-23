#include"thread_cache.h"

void* ThreadCache::Alloc(size_t size) {
	size_t index = SizeClass::List_Index(size);
	FreeList& freelist = _freelists[index];
	if (!freelist.Empty()) {
		return freelist.Pop();
	}
	else {
		return Fetch_From_CentralCache(index);
	}
}

void ThreadCache::Dealloc(void* ptr, size_t size) {
	size_t index = SizeClass::List_Index(size);
	FreeList& freelist = _freelists[index];
	freelist.Push(ptr);
}

void* ThreadCache::Fetch_From_CentralCache(size_t index) {
	size_t num = 20;
	size_t size = (index + 1) * 8;
	char* start = (char*)malloc(size*num);
	char* cur = start;
	for (int i = 0; i < num - 1; ++i) {
		char* next = cur + size;
		NextObj(cur) = next;
		cur = next;
	}
	NextObj(cur) = nullptr;
	
	void* head = NextObj(start);
	void* tail = cur;
	_freelists[index].PushRange(head, tail);
	return start;
}