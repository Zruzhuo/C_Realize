#include"thread_cache.h"
#include"central_cache.h"

void* ThreadCache::Alloc(size_t size) {
	size_t index = SizeClass::ListIndex(size);
	FreeList& freelist = _freelists[index];
	if (!freelist.Empty()) {
		return freelist.Pop();
	}
	else {
		return FetchFromCentralCache(SizeClass::RoundUp(size));
	}
}

void ThreadCache::Dealloc(void* ptr, size_t size) {
	size_t index = SizeClass::ListIndex(size);
	FreeList& freelist = _freelists[index];
	freelist.Push(ptr);
	//对象个数满足一定条件 | 内存大小
	size_t num = SizeClass::NumMoveSize(size);
	if (freelist.Num() >= num) {
		ListTooLong(freelist, num, size);
	}
}

void ThreadCache::ListTooLong(FreeList& freelist, size_t num, size_t size) {
	void* start = nullptr, *end = nullptr;
	freelist.PopRange(start, end, num);

	NextObj(end) = nullptr;
	CentralCache::GetInsatnce().ReleaseListToSpans(start, size);
}

void* ThreadCache::FetchFromCentralCache(size_t size) {
	size_t num = SizeClass::NumMoveSize(size);

	void* start = nullptr, *end = nullptr;
	size_t actual_num = CentralCache::GetInsatnce().FetchRangeObj(start, end, num, size);
	if (actual_num == 1) {
		return start;
	}
	else {
		size_t index = SizeClass::ListIndex(size);
		FreeList& list = _freelists[index];
		list.PushRange(NextObj(start), end, actual_num - 1);

		return start;
	}
}