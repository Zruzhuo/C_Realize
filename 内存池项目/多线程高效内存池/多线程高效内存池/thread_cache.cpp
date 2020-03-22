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

}