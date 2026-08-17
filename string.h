#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cassert>

using namespace std;

namespace bit
{
	class string
	{
		public:
			typedef char* iterator;
			typedef char* const_iterator;

			iterator begin()
			{
				return _str;
			}
			iterator end()
			{
				return _str+_size;
			}

			const iterator begin()const
			{
				return _str;
			}
			const iterator end()const
			{
				return _str + _size;
			}
			string()
			:_str(new char[1]{'\0'})//最重要的地方，string初始化不能为空
			,_size(0)
			,_capacity(0)
			{}  
			string(const char* str)
			{
				_size=strlen(str); //strlen不会计算\0
				_capacity=_size;
				//capacity不包含斜杠零
				_str=new char[_capacity+1];
				strcpy(_str,str);//把str字符串复制到_str
			}
			
			string(const string& s)
			{
				_str=new char[s._capacity+1];
				//strcpy(_str,s._str);
				memcpy(_str,s._str,s._size);
				_size=s._size;
				_capacity=s._capacity;
				_str[_size]='\0';
			}
			//对于深拷贝，上面运行的是常规写法，其实也可以用下面找小三的写法来写
			//string(const string& s)
			//{
			//	string tmp = s._str;//string tmp = s 这样写是会死递归调用拷贝构造的
			//	swap(_str, tmp._str);
			//	swap(_size, tmp._size);
			//	swap(_capacity, tmp._capacity);
			//}
			//赋值重载
			string& operator=(const string& s)//当然，仍然可以用上面的现代写法来写
			{
				if(this==&s)return *this;
				delete[] _str;
				_str = new char[s._capacity+1];
				//memcpy(_str,s._str,s._size);
				//_str[_size] = '\0';
				strcpy(_str,s._str);
				_size=s._size;
				_capacity=s._capacity;
				return *this;
			}
			~string()
			{
				delete[]_str;
				_str=nullptr;
				_size=0;
				_capacity=0;
			}
			size_t size()
			{
				return _size;
			}
			char& operator[](size_t pos)
			{
				assert(pos<_size&&pos>=0);
				return _str[pos];
			}
			const char* c_str()const
			{
				return _str;
			}
			size_t capacity()const
			{
				return _capacity;
			}
			void clear()
			{
				_str[0]='\0';
				_size=0;
			}
			void swap( string& s)
			{
				std::swap(_str,s._str);
				std::swap(_size,s._size);
				std::swap(_capacity,s._capacity);

			}
			void reserve(size_t n);
			void push_back(char ch);
			void append(const char* str);
			string& operator+=(const char* ch);
			string& operator+=(char ch);
			void insert(size_t pos,char ch);
			void insert(size_t pos,const char* s);
			void erase(size_t pos,size_t len=npos);//声明和实现处的npos只能有一处写
			size_t find(char ch,size_t pos);
			size_t find(const char* s,size_t pos);
			string substr(size_t pos,size_t len);

		private:
			char* _str;
			size_t _size;
			size_t _capacity;
			static const  size_t npos;
	};
	bool operator<(const string& s1, const string& s2);
	bool operator<=(const string& s1, const string& s2);
	bool operator>(const string& s1, const string& s2);
	bool operator>=(const string& s1, const string& s2);
	bool operator==(const string& s1, const string& s2);
	bool operator!=(const string& s1, const string& s2);
	ostream& operator<<(ostream& out,const string& s);
	istream& operator>>( istream& in,string& s);


	void test_string1();
}
