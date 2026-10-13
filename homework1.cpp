#include<iostream>
#include<cassert>
#include<algorithm>
using namespace std;


template<class element>
struct node
{
element data;
node* next;
};
// 前向声明类模板
template <typename element> class Linklist;

// 前向声明函数模板
template <typename element>
Linklist<element> fun3(Linklist<element> &l1, Linklist<element> &l2);

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
void push_back(element d);//尾插
void push_front(element d);//头插
void insert(size_t n,element d);//按位插入
element find(size_t i);//按位查找
size_t find(element d);//按值查找
element erase(size_t n);//按位删除
size_t erase(element d);//按值删除
void print_list();//打印链表
Linklist fun2();//实现规定的重排列
friend Linklist<element> fun3<element>(Linklist<element> &l1,Linklist<element> &l2);//实现题目3的要求
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
void Linklist<element>::push_back(element d)
{
    count++;
    node<element>*x=new node<element>;
    node<element> *p=head;
    while(p->next!=nullptr)
    {
        p=p->next;
    }
    p->next=x;
    x->next=nullptr;
    x->data=d;
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
Linklist<element> Linklist<element>::fun2()//实现规定的重排列
{
    Linklist<element> tmp;
    node<element> *p=head->next;
    while(p)
    {
        tmp.push_front(p->data);//将原链表元素头插进临时链表实现倒序存放
        p=p->next;
    }
     Linklist<element> re;
     size_t cnt=count/2;
     node<element> *p1=head->next;
     node<element> *p2=tmp.head->next;
     while(cnt>0)
     {
        cnt--;
        re.push_back(p1->data);
        re.push_back(p2->data);
        p1=p1->next;
        p2=p2->next;
     }
     if(count%2==1)//如果是奇数个元素的话，最后还要加上中间的那个元素
     {
        re.push_back(p1->data);
     }
     return re;
}
template<class element>
Linklist<element> fun3(Linklist<element> &l1,Linklist<element> &l2)//实现题目3的要求
{
    Linklist<element> re;
    //node<element> *work=re.head->next;
    node<element> *p1=l1.head->next;
    node<element> *p2=l2.head->next;
    //因为l1与l2是递增的,要实现re的递减最简单方法就是头插实现倒序插入
    while(p1||p2)
    {

        //l1与l2都没存完的情况
         if(p1&&p2)
         {
          if(p1->data<p2->data)
          {
                node<element> *tmp=p1->next;
                re.count++;
                p1->next=re.head->next;
                re.head->next=p1;
                p1=tmp;
          }
          else
          {
                node<element> *tmp=p2->next;
                re.count++;
                p2->next=re.head->next;
                re.head->next=p2;
                p2=tmp;
          }
         }
        //判断哪个先存完了
       if(p1==nullptr&&p2!=nullptr)
       {
        node<element> *tmp=p2->next;
        re.count++;
        p2->next=re.head->next;
        re.head->next=p2;
        p2=tmp;
       }
       if(p2==nullptr&&p1!=nullptr)
       {
        node<element> *tmp=p1->next;
        re.count++;
        p1->next=re.head->next;
        re.head->next=p1;
        p1=tmp;
       }
       

    }
    return re;
}
int main()
{
    int m,n;
    cout<<"分别输入两个链表的长度："<<endl;
    cin>>m>>n;
    Linklist<int>l1,l2;
    cout<<"分别输入两个链表的元素(为了方便检查,递增输入吧)："<<endl;
    for(int i=0;i<m;i++)
    {
        int tmp;
        cin>>tmp;
        l1.push_back(tmp);
    }   
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        l2.push_back(tmp);
    }
    Linklist<int>l3=fun3(l1,l2);
    cout<<"合并后的链表为："<<endl;
    l3.print_list();
    return 0;
}
// void fun(int num[],int n)
// {
//   int work=0,end=n-1;
//   while(work<end)
//   {
//     while(num[work]<0)
//     {
//       work++;
//     }
//     while(num[end]>=0)
//     {
//         end--;
//     }
//     //这个两个while循环使得work指向第一个非负数，end指向第一个负数
//     if(work<end)
//     {
//         int tmp=num[work];
//         num[work]=num[end];
//         num[end]=tmp;
//     }
    
//   }
// }
// int main()
// {

//     int num[1000];
//     int n;
//     cout<<"请输入数组的长度："<<endl;
//     cin>>n;
//     cout<<"请输入数组的元素：";
//     for(int i=0;i<n;i++)
//     {
//         cin>>num[i];
//     }
//     fun(num,n);
//     cout<<"处理后的数组为："<<endl;
//     for(int i=0;i<n;i++)
//     {
//         cout<<num[i]<<" ";
//     }
//     return 0;
// }