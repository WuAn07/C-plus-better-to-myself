#ifndef LINKLIST_H
#define LINKLIST_H
#include<iostream>
#include<cassert>


using namespace std;

template<class element>
struct node
{
element data;
node* next;
};
template<class element>
class Linklist
{
public:
Linklist();//构造
Linklist(element a[],int n);//必须要求a是从0位置开始存放的
~Linklist();
size_t get_length();//求链表长度
element get_data(size_t n);//得到第n个元素
node<element>* get_point(size_t i);//返回第i个元素的指针
void push_front(element d);//尾插
void insert(size_t n,element d);//按位插入
element find(size_t i);//按位查找
size_t find(element d);//按值查找
element erase(size_t n);//按位删除
size_t erase(element d);//按值删除
void print_list();//打印链表

private:
node<element> *head;
size_t count;
};

template<class element>
Linklist<element>::Linklist()
{
    head=new node<element>;
    count=0;
    head->next=nullptr;
}

template<class element>
Linklist<element>::Linklist(element a[],int n)
{
    head=new node<element>;
    head->next=nullptr;
    count=(size_t)n;
    for(int i=n-1;i>=0;--i)//从a的最后一个开始头插进去，使得链表中的元素与a中的元素顺序一样
    {
        node<element> *p=new node<element>;
        p->data=a[i];
        p->next=head->next;
        head->next=p;
    }
}

template<class element>
Linklist<element>::~Linklist()
{
    for(size_t i=1;i<=count;++i)
    {
       node<element>*p= head->next;
       head->next=p->next;
       delete p;
    }
    delete head;//删除头指针不能忘记
}

template<class element>
size_t Linklist<element>::get_length()
{
    return count;
}

template<class element>
element Linklist<element>::get_data(size_t n)
{
    assert(n<=count);
    element re;
    node<element> *p=head->next;
    for(size_t i=0;i<n-1;++i)
    {
       p=p->next;
    }
   re=p->data;
   return re;
}

template<class element>
node<element>* Linklist<element>::get_point(size_t i)//按位返回地址
{
    assert(i<=count&&i>=1);
    node<element> *p=head;
    size_t j=1;
    while(p&&j<=i)
    {
        j++;
        p=p->next;
    }
    return p;
}

template<class element>
void Linklist<element>::push_front(element d)
{
    count++;
    node<element>*x=new node<element>;
    x->next=head->next;
    x->data=d;
    head->next=x;
}


template<class element>
void Linklist<element>::insert(size_t n,element d)//n指的是第n个元素，插入的是第n个元素的位置
{
    assert(n<=count+1&&n>0);

    node<element> *p;
    p=head;
    size_t j=1;
    while(p&&j<=n-1)//工作指针要算到第n个元素的前面
    {
        j++;
        p=p->next;
    }
    node<element> *q=new node<element>;
    q->next=p->next;
    q->data=d;
    p->next=q;
    count++;
    
}



template<class element>
element Linklist<element>::erase(size_t n)//按位删除,n指的是第n个元素，应当大于1
{
    assert(n<=count&&n>=1);
    node<element> *p=head;
    
    size_t m=1;
    while(p&&m<=n-1)//工作指针依然要算到第n个元素的前面
    {
        p=p->next;
        ++m;
    }
    node<element> *q=p->next;
    element re=q->data;
    p->next=q->next;
    delete q;
    count--;
    return re;
}

template<class element>
element Linklist<element>::find(size_t i)//按位查找
{
    assert(i<=count&&i>=1);
    node<element> *p=head->next;
    size_t j=1;
    while(p&&j<i)
    {
        j++;
        p=p->next;
    }
    return p->data;
}

template<class element>
size_t Linklist<element>::find(element d)//按值查找,返回0代表找不到
{
    assert(count>=1);//排除空表情况
    node<element> *p=head->next;
    size_t cnt=1;
    while(p)
    {
        if(p->data==d)
            return cnt;
        cnt++;
        p=p->next;
       
    }
   return 0;
}
template<class element>
size_t Linklist<element>::erase(element d)//按值删除,返回的应当是该元素的位次，大于等于1才对
{

    size_t n=find(d);
    if(n==0)return 0;
     node<element>*p;
    if(n==1)p=head;
    else p=get_point(n-1);//p是要删除的上一个元素的指针
    node<element> *tmp=p->next;
    p->next=tmp->next;
    delete tmp;
    count--;//表长-1不能忘了，这破错误调了好久啊
    return n;
}

template<class element>
void Linklist<element>::print_list()
{
    node<element>*p=head->next;
    if(p==nullptr)
    {
        cout<<"空链表"<<endl;
        return ;
    }
    while(p->next!=nullptr)
    {
            cout<<p->data<<"->";
            p=p->next;
    }
    cout<<p->data<<endl;
}
#endif