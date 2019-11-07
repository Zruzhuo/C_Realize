#include<iostream>
#include<stdlib.h>

using namespace std;

template<class T>
struct ListNode
{
	ListNode(const T& val = T())
		:_pre(nullptr)
		,_next(nullptr)
		,_val(val)
	{}

	ListNode<T>* _pre;
	ListNode<T>* _next;
	T _val;
};

template<class T, class Ref, class Ptr>
struct List_Iterator
{
	typedef ListNode<T> Node;
	typedef List_Iterator<T, Ref, Ptr> Self;

	Node* _pNode;

	List_Iterator(Node* p = nullptr)
		:_pNode(p)
    {}
	List_Iterator(const Self& l)
		:_pNode(l._pNode)
	{}
	Ref operator*()
	{
		return _pNode->_val;
	}
	Ptr operator->()
	{
		return &(_pNode->_val);
	}
	Self& operator++()
	{
		_pNode = _pNode->_next;
		return *this;
	}
	Self operator++(int)
	{
		Self tmp(*this);
		_pNode = _pNode->_next;
		return tmp;
	}
	bool operator!=(const Self& l)
	{
		return _pNode != l._pNode;
	}
	bool operator==(const Self& l)
	{
		return _pNode == l._pNode;
	}
};

//template<class T, class Ref, class Ptr>//_pNode没有找到标识符，定义出错
//struct List_R_Iterator
//{
//	typedef ListNode<T> Node;
//	typedef List_R_Iterator<T, Ref, Ptr> Self;
//
//	Node* _pNode;
//
//	List_R_Iterator(Node* p = nullptr)
//		:_pNode(p)
//	{}
//	List_R_Iterator(const Self& l)
//		:_pNode(l._pNode)
//	{}
//	Ref operator*()
//	{
//		Node* tmp = _pNode;
//		return *(--tmp);
//	}
//	Ptr operator()
//	{
//		return &(operator*())
//	}
//	Self& operator++()
//	{
//		--_pNode;
//		return *this;
//	}
//	Self operator++(int)
//	{
//		Iterator tmp(_pNode);
//		--_pNode;
//		return tmp;
//	}
//	Self& operator--()
//	{
//		++_pNode;
//		return *this;
//	}
//	Self operator--(int)
//	{
//		Iterator tmp(_pNode);
//		++_pNode;
//		return tmp;
//	}
//	bool operator==(const Self& l)
//	{
//		return _pNode == l._pNode;
//	}
//	bool operator!=(const Self& l)
//	{
//		return _pNode != l._pNode;
//	}
//};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	typedef List_Iterator<T, T&, T*> Iterator;
	typedef List_Iterator<T, const T&, const T*> C_Iterator;
	//typedef List_R_Iterator<T, T&, T*> R_Iterator;
	//typedef List_R_Iterator<T, const T&, const T*> C_R_Iterator;
	List()
	{
		Create_Head();
	}
	List(int n, const T& val)
	{
		Create_Head();
		for (int i = 0; i < n; ++i)
			Push_Back(val);
	}
	/*List(Iterator first, Iterator last)
	{
		Create_Head();
		while (first != last)
		{
			Push_Back(*first);
			++first;
		}
	}*/
	List(const List<T>& l)
	{
		Create_Head();
		auto it = l.C_Begin();
		while (it != l.C_End())
		{
			Push_Back(*it);
			++it;
		}
	}
	~List()
	{
		Clear();
		delete _pHead;
		_pHead = nullptr;
	}
	List<T>& operator=(List<T> l)
	{
		swap(_pHead, l._pHead);
		return *this;
	}
	Iterator Begin()
	{
		return Iterator(_pHead->_next);
	}
	Iterator End()
	{
		return Iterator(_pHead);
	}
	C_Iterator C_Begin() const
	{
		return C_Iterator(_pHead->_next);
	}
	C_Iterator C_End() const
	{
		return C_Iterator(_pHead);
	}
	/*R_Iterator R_Begin()
	{
		return R_Iterator(_pHead);
	}
	R_Iterator R_End()
	{
		return R_Iterator(_pHead->_next);
	}
	C_R_Iterator C_R_Begin() const
	{
		return C_R_Iterator(_pHead);
	}
	C_R_Iterator C_R_End() const
	{
		return C_R_Iterator(_pHead->_next);
	}*/
	size_t Size() const
	{
		size_t count = 0;
		C_Iterator it = C_Begin();
		while (it != C_End())
		{
			++count;
			++it;
		}
		return count;
	}
	bool Empty() const
	{
		return _pHead == _pHead->_next;
	}
	void Clear()
	{
		Node* pcur = _pHead->_next;
		while (pcur != _pHead)
		{
			_pHead->_next = pcur->_next;
			delete pcur;
			pcur = _pHead->_next;
		}
		_pHead->_next = _pHead;
		_pHead->_pre = _pHead;
	}
	T& Front()
	{
		return _pHead->_next->_val;
	}
	const T& Front() const
	{
		return _pHead->_next->_val;
	}
	T& Back()
	{
		return _pHead->_pre->_val;
	}
	const T& Back() const
	{
		return _pHead->_pre->_val;
	}
	void Push_Back(const T& val)
	{
		Node* newback = new Node(val);
		_pHead->_pre->_next = newback;
		newback->_pre = _pHead->_pre;
		newback->_next = _pHead;
		_pHead->_pre = newback;
	}
	void Pop_Back()
	{
		if (_pHead != _pHead->_pre)
		{
			Node* newback = _pHead->_pre->_pre;
			newback->_next = _pHead;
			delete _pHead->_pre;
			_pHead->_pre = newback;
		}
	}
	void Push_Front(const T& val)
	{
		Node* newfront = new Node(val);
		_pHead->_next->_pre = newfront;
		newfront->_next = _pHead->_next;
		newfront->_pre = _pHead;
		_pHead->_next = newfront;
	}
	void Pop_Front()
	{
		if (_pHead != _pHead->_pre)
		{
			Node* newfront = _pHead->_next->_next;
			newfront->_pre = _pHead;
			delete _pHead->_next;
			_pHead->_next = newfront;
		}
	}
	Iterator Insert(Iterator pos, const T& val)//在pos节点前插入val，返回该位置
	{
		Node* newnode = new Node(val);
		Node* cur = pos._pNode;
		cur->_pre->_next = newnode;
		newnode->_pre = cur->_pre;
		newnode->_next = cur;
		cur->_pre = newnode;
		return Iterator(newnode);
	}
	Iterator Erase(Iterator pos)//删除pos位置的节点，返回下一个位置
	{
		Node* cur = pos._pNode;
		Node* pre = cur->_pre;
		Node* next = cur->_next;
		delete cur;
		pre->_next = next;
		next->_pre = pre;
		return Iterator(next);
	}
private:
	void Create_Head()
	{
		_pHead = new Node;
		_pHead->_next = _pHead;
		_pHead->_pre = _pHead;
	}
	Node* _pHead;
};

void print(const List<int>& l)
{
	auto it = l.C_Begin();
	while (it != l.C_End())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;
}
void test1()
{
	List<int> l(5, 9);
	List<int> k(7, 1);
	print(l);
	l.Push_Back(1);
	print(l);
	l.Push_Front(0);
	l.Pop_Back();
	print(l);
	l.Clear();
	cout << l.Empty() << endl;
	print(l);
	l = k;
	print(l);
	cout << l.Size() << endl;
	cout << l.Empty() << endl;
	l.Push_Back(9);
	l.Push_Front(0);
	print(l);
	cout << l.Front() << endl;
	cout << l.Back() << endl;
	l.Insert(++(l.Begin()), 10);
	print(l);
	l.Erase(++(l.Begin()));
	print(l);
}

int main()
{
	test1();
	system("pause");
	return 0;
}
