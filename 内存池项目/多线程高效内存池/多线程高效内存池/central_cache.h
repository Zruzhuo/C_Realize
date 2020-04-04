#pragma once

#include"common.h"

//单例模式
class CentralCache {
public:
	//从中心缓存获取一定量的对象给线程缓存
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t size);

	//将一定数量的对象释放到span跨度
	void ReleaseListToSpans(void* start, size_t size);

	//从spanlist或者页缓存获取一个span
	Span* GetOneSpan(size_t size);

	static CentralCache& GetInsatnce() {
		static CentralCache inst;
		return inst;
	}
private:
	CentralCache() {}

	CentralCache(const CentralCache&) = delete;

	SpanList _spanlists[NFREE_LIST];
};


