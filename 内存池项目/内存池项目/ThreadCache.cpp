#include"ThreadCache.h"

void* ThreadCache::Allocte(size_t size) 
{
	size_t index = SizeClass::ListIndex(size);
	FreeList& freeList = _freeLists[index];
	if (!freeList.Empty()) //index大小的链表不为空，可以直接申请内存
	{
		return freeList.Pop();
	}
	else//index大小的链表为空，所以去中心缓存申请num个index大小的内存块
	{
		size_t num = 20;//优化
		return FetchFromCentralCache(index);
	}
}
void ThreadCache::Deallocte(void* ptr, size_t size) 
{
	size_t index = SizeClass::ListIndex(size);
	FreeList& freeList = _freeLists[index];
	freeList.Push(ptr);

	/*if ()
	{
		ReleaseToCentralCache();
	}*/

}
void* ThreadCache::FetchFromCentralCache(size_t index)
{
	size_t num = 20;
	//模拟取内存对象的代码，验证Thread Cache逻辑
	size_t size = (index + 1) * 8;
	char* start = (char*)malloc(size * num);
	char* cur = start;
	for (size_t i = 0; i < num; ++i)
	{
		char* next = cur + size;
		NextObj(cur) = next;
		cur = next;
	}
	NextObj(cur) = nullptr;

	void* head = NextObj(start);
	void* end = cur;

	_freeLists[index].PushRange(head, cur);
	return start;	
		  
}