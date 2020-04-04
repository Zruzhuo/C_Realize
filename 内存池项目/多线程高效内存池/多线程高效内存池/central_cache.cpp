#include"central_cache.h"
#include"page_cache.h"

Span* CentralCache::GetOneSpan(size_t size) {
	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _spanlists[index];
	Span* it = spanlist.Begin();
	while (it != spanlist.End()) {
		if (!it->_freelist.Empty()) {
			return it;
		}
		else {
			it = it->_next;
		}
	}
	//页缓存获取一个span
	size_t numpage = SizeClass::NumMovePage(size);
	Span* span = pageCacheInst.NewSpan(numpage);
	//把span对象切成对应大小挂到span的freelist中
	char* start = (char*)(span->_pageid << 12);
	char* end = start + (span->_pagesize << 12);
	while (start < end) {
		char* obj = start;
		start += size;

		span->_freelist.Push(obj);
	}
	span->_objsize = size;
	spanlist.PushFront(span);

	return span;
}

size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t size) {
	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _spanlists[index];
	spanlist.Lock();

	Span* span = GetOneSpan(size);
	FreeList& freelist = span->_freelist;
	size_t actual_num = freelist.PopRange(start, end, num);
	span->_usecount += actual_num;

	spanlist.Unlock();

	return actual_num;
}

void CentralCache::ReleaseListToSpans(void* start, size_t size) {
	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _spanlists[index];
	spanlist.Lock();

	while (start) {
		void* next = NextObj(start);
		PAGE_ID id = (PAGE_ID)start >> PAGE_SHIFT;
		Span* span = pageCacheInst.GetIdToSpan(id);
		span->_freelist.Push(start);
		span->_usecount--;

		//表示当前span切出去的对象全部返回，可以将span还给页缓存，进行合并，减少内存碎片
		if (span->_usecount == 0) {
			size_t index = SizeClass::ListIndex(span->_objsize);
			_spanlists[index].Erase(span);
			span->_freelist.Clear();

			pageCacheInst.ReleaseSpanToPageCache(span);
		}
		start = next;
	}
	spanlist.Unlock();
}