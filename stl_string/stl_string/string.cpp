#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#pragma warning(disable:4996)
using namespace std;

class String
{
public:
	typedef const char* c_iterator;
	typedef char* iterator;
	c_iterator Begin()const
	{
		return _str;
	}
	iterator Begin()
	{
		return _str;
	}
	c_iterator End()const
	{
		return _str + _size;
	}
	iterator End()
	{
		return _str + _size;
	}
	String(const char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
		_size = strlen(str);
		_capacity = _size;
	}
	~String()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}
	String(const String& s)
		:_str(new char[s._size + 1])
		,_size(s._size)
		,_capacity(s._size)
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}
	const char* c_str()
	{
		return _str;
	}
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}
	size_t Size()
	{
		return _size;
	}
	size_t Capacity()
	{
		return _capacity;
	}
	void Reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	void Push_Back(char c)
	{
		if (_size == _capacity)
		{
			Reserve(_capacity * 2);
		}
		_str[_size] = c;
		++_size;
		_str[_size] = '\0';
	}
	void Append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			Reserve(_size + len);
		}
		strcpy(_str + _size, str);
		_size += len;
	}
	const String& operator+=(char c)
	{
		Push_Back(c);
		return *this;
	}
	const String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	bool operator>(const String& s)
	{
		char* str1 = _str;
		char* str2 = s._str;
		while (*str1 != '\0' && *str2 != '\0')
		{
			if (*str1 > *str2)
			{
				return true;
			}
			else if (*str1 < *str2)
			{
				return false;
			}
			str1++;
			str2++;
		}
		return false;
	}
	bool operator==(const String& s)
	{
		char* str1 = _str;
		char* str2 = s._str;
		while (*str1 != '\0' && *str2 != '\0')
		{
			if (*str1 != *str2)
			{
				return false;
			}
			str1++;
			str2++;
		}
		return true;
	}
	bool operator<(const String& s)
	{
		if ((*this > s)||(*this == s))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool operator!=(const String& s)
	{
		if (!(*this == s))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<=(const String& s)
	{
		if ((*this < s) && (*this == s))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>=(const String& s)
	{
		if ((*this > s) && (*this == s))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	size_t Find(const char c) const
	{
		for (size_t i = 0; i < _size; ++i)
		{
			if (_str[i] == c)
			{
				return i;
			}
		}
		return -1;
	}
	size_t Find(const char* str) const
	{
		size_t index = -1;
		size_t len = strlen(str);
		for (size_t i = 0; i < _size; ++i)
		{
			size_t j = i;
			size_t n = 0;
			while (n < len && j < _size && (_str[j++] == str[n++]));
			if (n == len)
			{
				index = i;
				break;
			}
		}
		return index;
	}
	String Substr(size_t pos, size_t n)
	{
		assert(pos < _size);
		String s;
		s._str = new char[n + 1];
		s._size = n;
		s._capacity = n;
		for (size_t i = 0; i < n; ++i)
		{
			s._str[i] = _str[pos];
			++pos;
		}
		return s;
	}
	String& Insert(size_t pos, char c)
	{
		assert(pos < _size);
		if (_size == _capacity)
		{
			Reserve(_capacity * 2);
		}
		for (size_t i = _size; i >= pos; --i)
		{
			_str[i + 1] = _str[i];
		}
		_str[pos] = c;
		return *this;
	}
	String& Insert(size_t pos, char* str)
	{
		assert(pos < _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			Reserve(_capacity + len);
		}
		for (size_t i = _size; i >= pos; --i)
		{
			_str[i + len] = _str[i];
		}
		for (size_t i = 0; i < len; ++i)
		{
			_str[pos] = str[i];
			++pos;
		}
		return *this;
	}
	
private:
	char* _str;
	size_t _size;
	size_t _capacity;
	friend ostream& operator<<(ostream& _cout, String& s);
};
ostream& operator<<(ostream& _cout, String& s)
{
	cout << s._str;
	return _cout;
}
void test()
{
	String s1("hello");
	s1.Push_Back('r');
	String::c_iterator it = s1.Begin();
	while (it != s1.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	s1.Push_Back('b');
	s1.Push_Back('c');
	cout << s1 << endl;
	/*String s1("hello");
	String s2("hello");
	cout << (s2 == s1) << endl;*/
}
int main()
{
	test();
	system("pause");
	return 0;
}