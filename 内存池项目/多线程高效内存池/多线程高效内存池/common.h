#pragma once

#include<iostream>
#include<assert.h>
#include<Windows.h>
using namespace std;

const size_t MAX_SIZE = 64 * 1024;
const size_t NFREE_LIST = MAX_SIZE / 8;
const size_t MAX_PAGES = 129;
const size_t PAGE_SHIFT = 12;

inline void*& NextObj(void* obj) {
	return *((void**)obj);
}

class FreeList {
public:
	void Push(void* obj){
		//头插
		NextObj(obj) = _freelist;
		_freelist = obj;
	}
	void PushRange(void* head, void* tail) {
		//插入一块
		NextObj(tail) = _freelist;
		_freelist = head;
	}
	void* Pop() {
		//头删
		void* obj = _freelist;
		_freelist = NextObj(obj);
		return obj;
	}
	size_t PopRange(void* start, void* end, size_t num) {
		size_t actual_num = 0;
		void* prev = nullptr;
		void* cur = _freelist;
		for (; actual_num < num && cur != nullptr; ++actual_num) {
			prev = cur;
			cur = NextObj(cur);
		}
		start = _freelist;
		end = prev;
		_freelist = cur;

		return actual_num;
	}
	bool Empty() {
		return _freelist == nullptr;
	}
private:
	void* _freelist = nullptr;
};

class SizeClass {
public:
	static size_t _RoundUp(size_t size, int alignment) {
		return (size + alignment - 1)&(~(alignment - 1));
	}
	static inline size_t RoundUp(size_t size) {
		assert(size <= MAX_SIZE);

		if (size <= 128) {
			return _RoundUp(size, 8);
		}
		else if (size <= 1024) {
			return _RoundUp(size, 16);
		}
		else if (size <= 8192) {
			return _RoundUp(size, 128);
		}
		else if (size <= 65536) {
			return _RoundUp(size, 1024);
		}
		return -1;
	}
	static size_t _List_Index(size_t size, int align_shift) {
		return ((size + (1 << align_shift) - 1) >> align_shift) - 1;
	}
	static size_t List_Index(size_t size) {
		assert(size <= MAX_SIZE);
		//每个区间有多少个链
		static int group_arr[4] = { 16,56,56,56 };
		if (size <= 128) {
			return _List_Index(size, 3);
		}
		else if (size <= 1024) {
			return _List_Index(size - 128, 4) + group_arr[0];
		}
		else if (size <= 8192) {
			return _List_Index(size - 1024, 7) + group_arr[1] + group_arr[0];
		}
		else if (size <= 65536) {
			return _List_Index(size - 8192, 10) + group_arr[2] + group_arr[1] + group_arr[0];
		}
		return -1;
	}
	//[2,512]个之间
	static size_t Num_Move_Size(size_t size) {
		if (size == 0) {
			return 0;
		}
		int num = MAX_SIZE / size;
		if (num < 2) {
			num = 2;
		}
		if (num < 512) {
			num = 512;
		}
		return num;
	}
	static size_t Num_Move_Page(size_t size) {
		size_t num = Num_Move_Size(size);
		size_t npage = num * size;

		npage >>= 12;
		if (npage == 0) {
			npage = 1;
		}
		return npage;
	}
};
/////////////////////////////////////////////////////////////////
//span跨度：管理页为单位的内存对象，本质是方便合并，解决内存碎片问题
//针对windows
#ifdef _WIN32
typedef unsigned int PAGE_ID;
#else
typedef unsigned long long PAGE_ID;
#endif

struct Span {
	PAGE_ID _pageid;//页号
	int _pagesize;//页的数量
	FreeList _freelist;//对象自由链表
	int _usecount;//内存块对象使用次数

	Span* _next;
	Span* _prev;
};

class SpanList {
public:
	SpanList() {
		_head = new Span;
		_head->_next = _head;
		_head->_prev = _head;
	}
	Span* Begin() {
		return _head->_next;
	}
	Span* End() {
		return _head;
	}
	void Insert(Span* pos, Span* newspan) {
		Span* prev = pos->_prev;
		prev->_next = newspan;
		newspan->_next = pos;
		pos->_prev = newspan;
		newspan->_prev = prev;
	}
	void Erase(Span* pos) {
		assert(pos != _head);
		Span* prev = pos->_prev;
		Span* next = pos->_next;

		prev->_next = next;
		next->_prev = prev;
	}
	void PushFront(Span* newspan) {
		Insert(_head->_next, newspan);
	}
	void PopFront() {
		Erase(_head->_next);
	}
	void PushBack(Span* newspan) {
		Insert(_head->_prev, newspan);
	}
	void PopBack() {
		Erase(_head->_prev);
	}
	bool Empty() {
		return Begin() == End();
	}
private:
	Span* _head;
};

inline static void* SystemAlloc(size_t num_page) {
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, num_page*(1 << PAGE_SHIFT),MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	//brk mmap等
#endif
	if (ptr == nullptr) {
		throw std::bad_alloc();
	}
	return ptr;
}