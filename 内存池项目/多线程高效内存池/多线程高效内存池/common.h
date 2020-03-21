#pragma once

#include<iostream>
using namespace std;

const size_t MAX_SIZE = 64 * 1024;
const size_t NFREE_LIST = MAX_SIZE / 8;

inline void*& NextObj(void* obj) {
	return *((void**)obj);
}

class FreeList {
public:
	void Push(void* obj){
		_freelist = NextObj(obj);

	}
	void* Pop() {

	}
private:
	void* _freelist = nullptr;
};