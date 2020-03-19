#include"ThreadCache.h"

void* ThreadCache::Allocte(size_t size) 
{
	size_t index = SizeClass::ListIndex(size);
	FreeList& freeList = _freeLists[index];
	if (!freeList.Empty()) //index��С������Ϊ�գ�����ֱ�������ڴ�
	{
		return freeList.Pop();
	}
	else//index��С������Ϊ�գ�����ȥ���Ļ�������num��index��С���ڴ��
	{
		size_t num = 20;//�Ż�
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
	//ģ��ȡ�ڴ����Ĵ��룬��֤Thread Cache�߼�
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