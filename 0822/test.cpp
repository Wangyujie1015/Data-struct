#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

class String
{
public:

	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin()
	{
		return _data;
	}

	iterator end()
	{
		return _data + _size;
	}

	String(const char* str = "")
	{
		_size = strlen(str);
		_data = new char[_size + 1];
		_capacity = _size;

		strcpy(_data, str);
	}

	String(const String& str)
		:_data(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(str._data);
		Swap(tmp);
	}

	void Swap(String& str)
	{
		swap(_data, str._data);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}

	String& operator=(String str)
	{
		Swap(str);
	}

	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _data[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _data[pos];
	}

	size_t size()const
	{
		return _size; 
	}

	void push_back(const char& ch)
	{
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		_data[_size++] = ch;

		_data[_size] = '\0';
	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];

			strcpy(tmp, _data);

			delete[] _data;

			_data = tmp;
			_capacity = n;
		}
	}

	void resize(size_t n, const char& ch = '\0')
	{
		if (n > _capacity)
		{
			reserve(n);
		}
		//_size < n < _capacity
		//填充字符
		if(n>_size)
		memset(_data + _size, ch, (n - _size) * sizeof(char));

		_size = n;
		_data[_size] = '\0';
	}

	void append(const char* str)
	{
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}

		memcpy(_data + _size, str, sizeof(char) * len);
		//strcpy(_data + _size, str);
		_size += len;
		_data[_size] = '\0';

	}

	void insert(size_t pos, const char& ch)
	{
		assert(pos <= _size);

		//检查容量
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}

		//移动元素
		size_t end = _size + 1;
		while (end > pos)
		{
			_data[end] = _data[end - 1];
			--end;
		}
		//插入
		_data[pos] = ch;
		//更新
		++_size;
	}

	void insert(size_t pos, const char* ptr)
	{
		assert(pos < _size);
		int len = strlen(ptr);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}


		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_data[end] = _data[end - len];
				--end;
		}

		memcpy(_data + pos, ptr, sizeof(char) * len);

		_size += len;
		_data[_size] = '\0';
	}

	void erase(size_t pos, size_t len)
	{
		assert(pos < _size);

		if (pos + len >= _size)
		{
			_size = pos;
			_data[_size] = '\0';
		}
		else
		{
			size_t start = pos + len;
			for (; start <= _size; start++)
			{
				_data[pos++] = _data[start];
			}
			_size -= len;
		}
		
	}

	String& operator+=(const String& str)
	{
		append(str._data);
		return *this;
	}
	String& operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	String& operator+=(const char ch)
	{
		push_back(ch);
		return *this;
	}

private:
	char* _data;
	size_t _size;
	size_t _capacity;
};

String operator+(const String& str1, const String& str2)
{
	String copy(str1);
	copy += str2;
	return copy;
	
}
String operator+(const String& str1, const char* str2)
{
	String str;
	str += str1;
	str += str2;
	return str;
}
String operator+(const char& ch, const String& str2)
{
	String copy(str2);
	copy += ch;
	return copy;
}

//class String
//{
//public:
//	String()
//		:_data(new char[1])
//	{
//
//	}
//
//	//全缺省构造函数
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])
//	{
//		strcpy(_data, str);
//	}
//
//	const char* c_str() const
//	{
//		return _data;
//	}
//
//	//深拷贝
//	String(const String& str)
//		:_data(new char[strlen(str._data)+1])
//	{
//		strcpy(_data, str._data);
//	}
//
//	String(const String& str)
//		:_data(nullptr)
//	{
//		String tmp(str._data);
//		swap(tmp._data,_data);
//	}
//
//	String& operator=(const String& str)
//	{
//		if (this != &str)
//		{
//			//1 释放原有空间
//			delete[] _data;
//			//2 申请新空间
//			_data = new char[strlen(str._data) + 1];
//			//3 拷贝内容
//			strcpy(_data, str._data);
//		}	
//		return *this;
//	}
//
//	String& operator=(String str)
//	{
//		swap(str._data, _data);
//	}
//
//	~String()
//	{
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr; 
//		}
//	}
//private:
//	char* _data;
//};