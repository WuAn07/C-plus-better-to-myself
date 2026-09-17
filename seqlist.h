#ifndef SEQLIST_H
#define SEQLIST_H
#include<iostream>
#include<cassert>
#include<iomanip>
#include<map>
using namespace std;
const int capacity=1000;

template<typename element>
class seqlist;

template<typename element>
void set_same(seqlist<element>& a,seqlist<element>& b);//同类型ab，a存ab交，b'存ab并

template<typename element>
class seqlist
{
public:
	seqlist();//无参
	seqlist(element a[], int n);//有参
	~seqlist(){}//析构
	int get_length();//获得表长
	element* get_datalist()
	{
		return data;
	}
	element get_item(int i);//按位获取
	int locate(element x);//按值查找
	void push_back(element x);//尾插

	void insert(int i,element x);//按位插入
	element _delete(int i);//删除并返回删除元素
	void erase();//删除所有元素
	bool empty();//判空
	void printlist();//打印
	void delete_same();//去重
	friend void set_same<element>(seqlist<element>& a, seqlist<element>& b);
private:	
	int length;
	element data[capacity+1];//	处理掉了下标0的地方，方便管理

};
//template<typename element>
//void set_same(seqlist<element> a,seqlist<element> b);//同类型ab，a存ab交，b'存ab并

template<typename element>
seqlist<element>::seqlist()
{
	length = 0;
}

template<typename element>
seqlist<element>::seqlist(element a[], int n)
{
	assert(n < capacity);
	for(int i = 1; i <= n; ++i)
		data[i] = a[i];
	length = n;

}

template<typename element>
int seqlist<element>::get_length()
{
	return length;
}

template<typename element>
element seqlist<element>::get_item(int i)//按位查找
{
	assert(i <= length);
	return data[i];
}

template<typename element>
int seqlist<element>::locate(element x)//按值查找
{
	for (int i = 1; i <= length; ++i)
		if (data[i] == x)return i;
	return 0;
}
template<typename element>
void  seqlist<element>::push_back(element x)//尾插
{
	assert(length<=capacity);
	data[++length]=x;
}
template<typename element>
void seqlist<element>::insert(int i, element x)//按位插入
{
	assert(i <= length + 1);
	for (int j = length + 1; j > i; j--)
	{
		data[j] = data[j - 1];
	}
	data[i] = x;
	length++;
}

template<typename element>
element seqlist<element>::_delete(int i)//删除并返回删除元素
{
	assert(i <= length);
	element tmp = data[i];

	for (int j = i; j < length; ++j)
		{
			data[j] = data[j + 1];
		}
		length--;
	return tmp;
}
template<typename element>
void seqlist<element>::erase()
{
	length=0;
}
template<typename element>
bool seqlist<element>::empty()//判空
{
	return length == 0 ? true : false;
}

template<typename element>
void seqlist<element>::printlist()//打印
{
	if(length==0)cout<<setw(5)<<"这是一个空表"<<endl;
	for (int i = 1; i <= length; ++i)
		cout  << data[i]<<"   ";
	cout << endl;
}
template<typename element>
void seqlist<element>::delete_same()//去重
{
	map<element,int>mp;
	for (int i = length; i >=1; --i)//一定要从后遍历，这个bug找了好久啊，从前遍历会导致多个重复元素无法删尽
	{
		mp[data[i]]++;
		if (mp[data[i]] > 1)
		{
			_delete(i);
		}
	}
}
template<typename element>
void set_same(seqlist<element>& a, seqlist<element> &b)
{
	assert(a.data[0]==b.data[0]);
	a.delete_same();//先给a，b去重
	b.delete_same();
	seqlist<element>tmp(a.data,a.get_length());
	tmp.printlist();
	//这里好的思路有一种：利用map性质：可以利用map，但显得有些大材小用了；另外可以再新建一个类似map的数据结构，
	//键位为element，值为int存储该element有多少个
	// map的时间复杂度为O(n)，利用空间来节约时间
	//或者利用双指针来写，这个的时间复杂度为
	map<element,int>mp1;
	map<element,int>mp2;
	for (int i = 1; i <= a.get_length(); ++i)
	{
		mp1[a.data[i]]++;
	}
	a.erase();
	for (int i = 1; i <= b.get_length(); ++i)
	{
		if (mp1[b.data[i]] != 0) {
			a.push_back(b.data[i]);
		}
		mp2[b.data[i]]++;
	}
	for (int i = 1; i <= tmp.length; i++)
	{
		if(mp2[tmp.data[i]]==0)b.push_back(tmp.data[i]);
	}
	a.delete_same();//再给a，b去重
	b.delete_same();
}
#endif