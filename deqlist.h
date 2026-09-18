#ifndef DEQLIST_H
#define DEQLIST_H   

#include <iostream>
#include<cassert>
#include<map>
#include<sstream>
#include<iomanip>
using namespace std;

// 前置声明，让 Depth 特化能认出 Deqlist 这个名字
template<class element> class Deqlist;

// 判断维度
template<typename T>
struct Depth { static const int value = 0; };

template<typename U>
struct Depth< Deqlist<U> > { static const int value = 1 + Depth<U>::value; };

template <class element>
class Deqlist
{
public:
    Deqlist();
    Deqlist(size_t capacity);
    Deqlist(const Deqlist<element> &other);
    ~Deqlist();
    size_t get_size();
    size_t get_capacity();
    void reserve(size_t n);
    void push_back(const element &value);
    void push_front(const element &value);
    element pop_back();//尾删并返回删除元素s
    element pop_front();//头删并返回删除元素
    void insert(size_t pos,const element &value);//在pos位置插入元素,这个pos指的是数组的下标，从0开始
    element erase(size_t pos);//删除pos位置的元素,并且返回该值
    int erase(const element &value);//删除value元素,并且返回该元素的最小下标,重载了
    element search(size_t pos);//查找pos位置的元素,并且返回该值
    int search(const element &value);//查找value元素的位置,并且返回该值,重载了
    void clear();//清空顺序表
    
    //上面都是小旮旯咪，下面的要更好玩了啊
    void erase_same();//对两个顺序表进行去重操作
    template <class T>
   friend void set_both(Deqlist<T> &list1, Deqlist<T> &list2);//友元函数，实现两个表的交并集操作，前者存交集，后者存并集
   void print_deqlist();//打印顺序表

        //运算符重载开始
    template <class T>
    friend ostream &operator<<(ostream &os,const Deqlist<T> &list);//重载<<运算符
    Deqlist<element> &operator=(const Deqlist<element> &other);//拷贝复制重载
    bool operator==(const Deqlist<element> &other)const;//判断是否相等
    bool operator!=(const Deqlist<element> &other)const;//判断是否不等
    element& operator[](size_t n);//重载[]
    //重载bengin end 有点忘记了
//     typedef element* iterator;
//     typedef element* const_iterator;
//     iterator begin()
//     {
//         return data;
//     }
//     iterator end()
//     {
//         return sizeof(element)*size+data;
//     }
//    const iterator begin()const
//    {0
//         return data;
//    }
//    const iterator end()const
//    {
//     return data+sizeof(element)*size;
//    }
private:
size_t size;//元素个数
size_t capacity;//顺序表容量
element *data;
//map<element,size_t> mp;//对顺序表的优化吧，牺牲了一定的空间，换取其他操作时间上的便利
};
//自动构造函数
template <class element>
Deqlist<element>::Deqlist()
{
    size = 0;
    capacity = 0;
    data = new element[capacity];
}
//限定容量构造
template <class element>
Deqlist<element>::Deqlist(size_t c)
{
    size = 0;
    this->capacity = c;
    data = new element[c];
}
//拷贝构造
template <class element>
Deqlist<element>::Deqlist(const Deqlist<element> &other)
{
    size=other.size;
    capacity=other.capacity;
    data=new element[capacity];
    for(size_t i=0;i<other.size;++i)
    {
        data[i]=other.data[i];
    }
}
//析构
template <class element>
Deqlist<element>::~Deqlist()
{
    delete[] data;
    data=nullptr;
}
template<class element>
size_t Deqlist<element>:: get_size()
{
    return size;
}
template<class element>
size_t Deqlist<element>:: get_capacity()
{
    return capacity;
}
//自动扩容并完成数据的转移，使得每次存储的空间利用率尽量高一点
template <class element>
void Deqlist<element>::reserve(size_t n)
{
    if(n>capacity)
    {
        element *tmp=new element[n];
       for(size_t i=0;i<size;++i)
        {
            tmp[i]=data[i];
        }   
        delete[] data;
        data=tmp;
        // mp.clear();
        // for(size_t i=0;i<size;++i)
        // {
        //     mp[data[i]]++;
        // }
        capacity=n;
    }
}
//尾插
template <class element>
void Deqlist<element>::push_back(const element &value)
{
    //每一次进行元素增加前要查看是否要扩充
    if(size==capacity)
    {
        reserve(capacity==0?4:capacity*2);
    }
    data[size++]=value;
    // mp[value]++;
}

//头插
template <class element>
void Deqlist<element>::push_front(const element &value)
{
    if(size==capacity)
    {
        reserve(capacity==0?4:capacity*2);
    }
    //元素移位
    for(size_t i=size;i>0;--i)
    {
        data[i]=data[i-1];
    }
    data[0]=value;
    ++size;
    // mp[value]++;
}
//未删
template <class element>
element Deqlist<element>::pop_back()
{
    assert(size>0);
    //mp[data[size-1]]--;
    element tmp=data[size-1];
    --size; 
    return tmp;

}

//头删
template <class element>
element Deqlist<element>::pop_front()
{
    assert(size>0);
    element tmp=data[0];
    for(size_t i=0;i<size-1;++i)
    {
        data[i]=data[i+1];
    }
    --size;
    // mp[tmp]--;
    return tmp;
}

//在pos位置插入元素,pos指的是数组的下标，从0开始
template <class element>
void Deqlist<element>::insert(size_t pos,const element &value)
{
        assert(pos<=size);
        if(size==capacity)
        {
            reserve(capacity==0?4:capacity*2);
        }
        for(size_t i=size;i>pos;--i)
        {
            data[i]=data[i-1];
        }
        data[pos]=value;
        size++;
        // mp[value]++;
}
 //删除pos位置的元素,并且返回该值
template <class element>
element Deqlist<element>::erase(size_t pos)
{
    assert(pos<size);
    element tmp=data[pos];
    for(size_t i=pos;i<size-1;++i)
    {
        data[i]=data[i+1];
    }
    // mp[tmp]--;
    --size;
    return tmp;
}

//删除value元素,并且返回该元素的最小下标,重载了
template <class element>
int Deqlist<element>::erase(const element &value)
{
    // if(mp[value]==0)return -1;
    for(size_t i=0;i<size;++i)
    {
        if(data[i]==value)
        {
            erase(i);
            return (int)i;
        }
    }
    return -1;
}
//查找pos位置的元素,并且返回该值
template <class element>
element Deqlist <element>::search(size_t pos)
{
    assert(pos<size);
    return data[pos];
}
//查找value元素的位置,并且返回该值,重载了
template <class element>
int Deqlist<element>::search(const element &value)
{
    // if(mp[value]==0)return -1;//先行判断了value是否在表中，好像节约了时间哈哈
    for(size_t i=0;i<size;++i)
    {
        if(data[i]==value)
        {
            return (int)i;
        }
    }
    return -1;
}

//清空顺序表
template <class element>
void Deqlist<element>::clear()
{
    size=0;
    //delete[] data;
    //只是删除元素，但表的容量不变,到底要不要变呢？问问老师吧
    //mp.clear();
}

//去重
template <class element>
void Deqlist<element>::erase_same()
{
    map<element,size_t>mp;
    //从这个操作再开始使用mp比较好，因为无论怎么样总要遍历一遍
    for(size_t i=size-1;i>0;--i)
    {
        mp[data[i]]++;
        if(mp[data[i]]>1)
        {
            erase(i);
        }
    }
}
//友元函数，实现两个表的交并集操作，前者存交集，后者存并集
template <class element>
void set_both(Deqlist<element> &list1, Deqlist<element> &list2)
{
    //先去重
    list1.erase_same();
    list2.erase_same();
    Deqlist<element>tmp1(list1);//拷贝一份list1，方便后续操作
    map<element,size_t >mp1;
    map<element,size_t>mp2;
    for(size_t i=0;i<list1.size;++i)
    {
        mp1[list1.data[i]]++;
    }
    list1.clear();//方便存交集
    for(size_t i=0;i<list2.size;++i)
    {
        if(mp1[list2.data[i]]>0)
        {
            list1.push_back(list2.data[i]);
        }
        mp2[list2.data[i]]++;
    }
    for(size_t i=0;i<tmp1.size;++i)
    {
        if(mp2[tmp1.data[i]]==0)
        {
            list2.push_back(tmp1.data[i]);
        }
    }
}

//打印顺序表
//最难设计的了啊！！！！！
//要解决的问题有：
//1 如何设置表的最大长度？
//2 如何使每一列的宽度相同且不耗用过多的空间？
//3 如何设置表格边界使得打印有序？
//1 把所有元素转为string类的计算总长度或许可行；
//2 计算每一列的最大长度，然后这一列的宽度就以最大长度为准了，但如何把长度小的元素打印在中间呢？
//3 只能循环嵌套了
template<class element>
void Deqlist<element>::print_deqlist()
{
    //首先要判断是一维还是二维，这个是最难的地方，需要用到模板递归
    if constexpr (Depth<element>::value == 0)//编译期的判断if，专门解决判断是否为二维一维
    {
        //一维打印
        //------------
        //| 123 | 45 |
        //------------
        size_t len=0;
        for(size_t i=0;i<size;++i)
        {
            ostringstream s;
            s<<data[i];
            len+=s.str().size();
        }
        for(size_t i=0;i<len+size*3+2;++i)
        {
            cout<<"-";
        }
        cout<<endl;
        for(size_t i=0;i<size;++i)
        {
            cout<<"| "<<data[i]<<" ";
        }
        cout<<" |"<<endl;
        for(size_t i=0;i<len+size*3+2;++i)
        {
            cout<<"-";
        }
        cout<<endl;
    }
    else if constexpr (Depth<element>::value == 1)     // 二维
{
    // 1. 求最大列数
    size_t cols = 0;
    for(size_t i = 0; i < size; ++i)
        if(data[i].get_size() > cols) cols = data[i].get_size();

    if(cols == 0) { cout << "空表" << endl; return; }

    // 2. 每列独立求最大宽度（这是你要的核心）
    size_t* mlen = new size_t[cols]();     // () 全部初始化 0
    for(size_t i = 0; i < size; ++i)
    {
        for(size_t j = 0; j < data[i].get_size(); ++j)
        {
            ostringstream s;
            s << data[i][j];
            size_t w = s.str().size();
            if(w > mlen[j]) mlen[j] = w;   // ← 关键：跟旧值比
        }
    }

    // 3. 画一条横线：每列宽度是 mlen[j]+2（左右各一个空格）
    auto line = [&]() {
        cout << "  +";
        for(size_t j = 0; j < cols; ++j)
            cout << string(mlen[j] + 2, '-') << "+";
        cout << "\n";
    };

    // 4. 逐行打印
    line();
    for(size_t i = 0; i < size; ++i)
    {
        cout << "  |";
        for(size_t j = 0; j < cols; ++j)
        {
            string s;
            if(j < data[i].get_size())
            {
                ostringstream os;
                os << data[i][j];
                s = os.str();
            }
            cout << " " << s;
            for(size_t k = s.size(); k < mlen[j]; ++k) cout << " ";
            cout << " |";
        }
        cout << "\n";
        line();
    }

    delete[] mlen;
        }
    

    // if(size==0)
    // {
    //     cout<<"这是一个空表哦"<<endl;
    //     return ;
    // }
    // for(size_t i=0;i<size;++i)
    // {
    //     if(data[i]==data[i+1])                 //我发现不进行对顺序表的元素进行判断的话会导致打印时出现对不齐的bug，所以要重载==判断再决定怎么输出
    //         cout<<data[i]<<"  ";
    //     else cout<<data[i]<<"  ";//如果data的元素本身是顺序表就需要对<<进行重载了
    // }
    // cout<<endl;
    }

//重载<<运算符
template <class T>
ostream &operator<<(ostream &os,const Deqlist<T> &list)
{
    if(list.size==0)
    {
        os<<"这是一个空表哦"<<endl;
        return os;
    }
    for(size_t i=0;i<list.size;++i)
    {
        os<<list.data[i]<<"  ";
    }
    os<<endl;
    return os;
}

//拷贝复制重载
template <class element>
Deqlist<element> &Deqlist<element>::operator=(const Deqlist<element> &other)
{
    if(this==&other)
    {
        return *this;
    }
    delete[] data;
    this->size=other.size;
    this->capacity=other.capacity;
    this->data=new element[capacity];
    for(size_t i=0;i<other.size;++i)
    {
        this->data[i]=other.data[i];
    }
    return *this;
}

//判断是否相等
template<class element>
bool Deqlist<element>::operator==(const Deqlist<element> &other)const
{
    if(size!=other.size)
        return false;
    
    for(size_t i=0;i<size;++i)
    {
        if(data[i]!=other.data[i])
            return false;
    }
    return true;
}
template<class element>
bool Deqlist<element> :: operator!=(const Deqlist<element> &other)const
{
    return !(*this==other);
}

//重载[]
template <class element>
element& Deqlist<element>:: operator[](size_t n)
{
    assert(n<size);
    return data[n];
}

// template <class element>
// iterator Deqlist<element>:: begin()
// {
//     return data;
// }
// template <class element>
// iterator Deqlist<element>::end()
// {
//     return sizeof(element)*size+data;
//  }
// template<element>
// const iterator Deqlist<element>:: begin()const
// {
//     return data;
// }
// template<element>
// const iterator Deqlist<element>:: end()const
// {
//     return data+sizeof(element)*size;
// }
#endif