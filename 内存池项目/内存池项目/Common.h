#pragma once

#include<iostream>
using namespace std;

const size_t MAX_SIZE = 64 * 1024;
const size_t N_FREE_LIST = MAX_SIZE / 8;

inline void*& NextObj(void* obj)
{
	return *((void**)obj);
}

class FreeList {
public:
	void Push(void* obj) //Í·²å
	{
		NextObj(obj) = _freelist;
		_freelist = obj;
	}
	void PushRange(void* head, void* tail)
	{
		NextObj(tail) = _freelist;
		_freelist = head;
	}
	void* Pop() //Í·É¾
	{
		void* obj = _freelist;
		_freelist = NextObj(obj);
		return obj;
	}
	bool Empty()
	{
		return _freelist == nullptr;
	}
private:
	void* _freelist = nullptr;
};

class SizeClass
{
public:
	static size_t ListIndex(size_t size)
	{
		if (size % 8 == 0)
		{
			return size / 8 - 1;
		}
		else
		{
			return size / 8;
		}
	}
};