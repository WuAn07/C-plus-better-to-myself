#ifndef BITREE_H
#define BITREE_H

#include<iostream>
#include<cassert>

using namespace std;

template <typename element>
class bitree_node
{
public:
    bitree_node(element x ,bitree_node<element> *l=nullptr,bitree_node<element> *r=nullptr)
    {
        data=x;
        lchild=l;
        rchild=r;
    }
    element data;
    bitree_node<element>* lchild;
    bitree_node<element>* rchild;
};

template <typename element>
class bitree
{
public:
    bitree();//无参构造函数
    bitree(const bitree<element>&);//拷贝构造函数,先把遍历什么的写了再补充吧
    ~bitree();//析构函数,同上.......
    int get_height(bitree_node<element>* _root);//递归获取树的高度
    int get_size();//获取树的节点数
    bool empty();//判空
    void clear(bitree_node<element>* _root);//递归形式的清空
    void set_root(bitree_node<element>* node);//设置根节点
    void insert_lchild(bitree_node<element>* parent,bitree_node<element>* child);//插入左孩子,前父节点,后子节点
    void insert_rchild(bitree_node<element>* parent,bitree_node<element>* child);//插入右孩子
    void preorder(bitree_node<element>* _root);//先序遍历
    void inorder(bitree_node<element>* _root);//中序遍历
    void postorder(bitree_node<element>* _root);//后序遍历
    void levelorder(bitree_node<element>* _root);//层次遍历
    void no_dfs_preorder(bitree_node<element>* _root);//非递归前序遍历
    void order_leaves(bitree_node<element>* _root);//按层次遍历叶子节点
    bitree_node<element>* find(bitree_node<element>* _root,element target);//查找节点,返回节点指针,没找到返回空指针
    
private:

    bitree_node<element>* root;
    int height;
    int size;

};

template <typename element>
bitree<element>::bitree()
{
    root=nullptr;
    height=0;
    size=0;
}

template <class element>
bitree<element>::~bitree()
{
    clear(root);
}
template <typename element>
int bitree<element>::get_height(bitree_node<element>* _root)
{
    if (_root == nullptr)
        return 0;
    int left_height = get_height(_root->lchild);
    int right_height = get_height(_root->rchild);
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

template <typename element>
int bitree<element>::get_size()
{
    return size;
}

template <typename element>
bool bitree<element>::empty()
{
    return size==0;
}

template <typename element>
void bitree<element>::clear(bitree_node<element>* _root)
{
    size=0;
    height=0;
    if (_root)//后序遍历清空
    {
        clear(_root->lchild);
        clear(_root->rchild);
        delete _root;
    }
}

template <typename element>
void bitree<element>::set_root(bitree_node<element>* node)
{
    if(node==root)return ;
    clear();
    root=node;
    size=1;
    height=1;
}

template <typename element>
void bitree<element>::insert_lchild(bitree_node<element>* parent,bitree_node<element>* child)
{
    assert(parent!=nullptr);
    assert(parent->lchild==nullptr);
    parent->lchild=child;
    size++;
    height = get_height(root); 
}

template <typename element>
void bitree<element>::insert_rchild(bitree_node<element>* parent,bitree_node<element>* child)
{
    assert(parent!=nullptr);
    assert(parent->rchild==nullptr);
    parent->rchild=child;
    size++;
    height = get_height(root); 
}

template <typename element>
void bitree<element>::preorder(bitree_node<element>* _root)
{
    if (_root)
    {
        cout << _root->data << " ";
        preorder(_root->lchild);
        preorder(_root->rchild);
    }
}

template <typename element>
void bitree<element>::inorder(bitree_node<element>* _root)
{
    if (_root)
    {
        inorder(_root->lchild);
        cout << _root->data << " ";
        inorder(_root->rchild);
    }
}

template <typename element>
void bitree<element>::postorder(bitree_node<element>* _root)
{
    if (_root)
    {
        postorder(_root->lchild);
        postorder(_root->rchild);
        cout << _root->data << " ";
    }
}

template <typename element>
void bitree<element>::levelorder(bitree_node<element>* _root)
{
    if(_root==nullptr)
     {
        cout<<"树为空"<<endl;
        return;
     }
     
     bitree_node<element>* q =new bitree_node<element>*[size];
     int front=0,rear=0;
     q[rear++]=_root;
     while(front<rear)
     {
        bitree_node<element>* p=q[front++];
         cout<<p->data<<" ";
         if(p->lchild!=nullptr)
             q[rear++]=p->lchild;
         if(p->rchild!=nullptr)
             q[rear++]=p->rchild;
     }
    delete []q;
     
}

template <class element>
void bitree<element>:: order_leaves(bitree_node<element>* _root)
{
    //简单做法就是遍历一遍树,把无左右孩子的节点给输出就行,既然是按层次遍历,那就要运用层序了
    if(_root==nullptr)
    {
        cout<<"空树"<<endl;
        return ;
    }
    bitree_node<element>* q = new bitree_node<element>*[size];
     int front=0,rear=0;
     q[rear++]=_root;
     while(front<rear)
     {
        bitree_node<element>* p=q[front++];
         if(p->rchild==nullptr&&p->lchild==nullptr)
         {
            cout<<p->data<<" ";
         }
         if(p->lchild!=nullptr)
             q[rear++]=p->lchild;
         if(p->rchild!=nullptr)
             q[rear++]=p->rchild;
    }
    delete []q;
}

template<class element>
 void bitree<element>::no_dfs_preorder(bitree_node<element>* _root)//非递归遍历
 {
    bitree_node<element>* s=new bitree_node<element>* [size];
    int top=0;
    s[top++]=_root;
    while(top&&s[top])
    {
        bitree_node<element>* tmp=s[top];
        cout<<s[top]->data<<" ";
        top--;
         if(tmp->rchild)
        {
            s[top++]=tmp->rchild;
        }
         if(tmp->lchild)
        {
            s[top++]=tmp->lchild;
        }

    }
    delete []s;
 }

template <class element>
bitree_node<element>* bitree<element>::find(bitree_node<element>* _root,element target)
{
    // 常规思路就是遍历一遍寻找目标值
    if(_root==nullptr)
    {
        return nullptr;
    }
    else{
        if(_root->data==target)return _root;
        find(_root->lchild,target);
        find(_root->rchild,target);
    }
}
#endif
