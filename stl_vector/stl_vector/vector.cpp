#include<iostream>
#include<assert.h>
#include<string.h>

using namespace std;

template<class T>
class Vector
{
public:
	typedef T* Iterator;
	typedef const T* c_Iterator;

	Iterator Begin()
	{
		return _start;
	}
	Iterator End()
	{
		return _finish;
	}
	c_Iterator Begin() const
	{
		return _start;
	}
	c_Iterator End() const
	{
		return _finish;
	}
	size_t Size()
	{
		return _finish - _start;
	}
	size_t Capacity()
	{
		return _endOfStorage - _start;
	}
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}
	Vector(int n, const T& value = T())
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		Reserve(n);
		while (n--)
		{
			Push_Back(value);
		}
	}
	Vector(const Vector<T>& v)
	{
		_start = new T[v.size()];
		memcpy(_start, v._start, sizeof(T)*v.size());
		_finish = _start + v.size();
		_endOfStorage = _start + v.size();
	}
	~Vector()
	{
		delete[] _start;
		_start = _finish = _endOfStorage = nullptr;
	}
	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}
	Vector<T>& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}
	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			size_t size = Size();
			T* tmp = new T[n];
			if (_start)
			{
				for (size_t i = 0; i < size; ++i)
				{
					tmp[i] = _start[i];
				}
			}
			_start = tmp;
			_finish = tmp + size;
			_endOfStorage = _start + n;
		}
	}
	void Resize(size_t n, const T& value = T())
	{
		if (n <= Size())
		{
			_finish = _start + n;
			return;
		}
		if (n > Capacity())
		{
			Reserve(n);
		}
		Iterator it = _finish;
		Iterator _finish = _start + n;
		if (it != _finish)
		{
			*it = value;
			++it;
		}
	}
	Iterator Insert(Iterator pos, const T& x)
	{
		assert(pos <= _finish);
		if (_finish == _endOfStorage)
		{
			size_t size = pos - _start;
			size_t newcapacity = Capacity() == 0 ? 1 : Capacity() * 2;
			Reserve(newcapacity);
			pos = _start + size;
		}
		Iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end + 1) = *end;
			--end;
		}
		*pos = x;
		++_finish;
		return pos;
	}
	Iterator Erase(Iterator pos)
	{
		assert(pos <= _finish);
		Iterator begin = pos + 1;
		while (begin != _finish)
		{
			*(begin - 1) = *begin;
			++begin;
		}
		--_finish;
		return pos;
	}
	void PushBack(const T& x)
	{
		Insert(End(), x);
	}
	void PopBack()
	{
		Erase(End() - 1);
	}
	T& operator[](size_t pos)
	{
		return _start[pos];
	}
private:
	Iterator _start;
	Iterator _finish;
	Iterator _endOfStorage;
};
void test1()
{
	Vector<int> v;
	v.PushBack(4);
	v.PushBack(3);
	v.PushBack(2);
	v.PushBack(1);
	v.PushBack(0);
	v.PopBack();
	v.PopBack();
	Vector<int>::c_Iterator it = v.Begin();
	while (it != v.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	test1();
	system("pause");
	return 0;
}