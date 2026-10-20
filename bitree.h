#ifndef BITREE_H
#define BITREE_H

#include<iostream>
#include<cassert>

using namespace std;

template <typename element>
class bitree_node
{
public:
    element data;
    bitree_node<element>* lchild;
    bitree_node<element>* rchild;
}

template <typename element>
class bitree
{
private:
    bitree();//无参构造函数
    bitree(const bitree<element>&);//拷贝构造函数,先把遍历什么的写了再补充吧
    ~bitree();//析构函数,同上.......
    int get_height();//获取树的高度
    int get_size();//获取树的节点数
    bool empty();//判空
    void clear();//清空
    void set_root(bitree_node<element>*);//设置根节点
    void insert_lchild(bitree_node<element>*,bitree_node<element>*);//插入左孩子,前面为要插的节点,后面为要插入的节点,后面为空节点
    void insert_rchild(bitree_node<element>*,bitree_node<element>*);//插入右孩子
    void preorder(bitree_node<element>*);//先序遍历
    void inorder(bitree_node<element>*);//中序遍历
    void postorder(bitree_node<element>*);//后序遍历
    void levelorder(bitree_node<element>*);//层次遍历
    void order_leaves(bitree_node<element>*);//按层次遍历叶子节点
    bitree_node<element>* find(bitree_node<element>*,element);//查找节点,返回节点指针,没找到返回空指针
    
public:

    bitree_node<element>* root;
    int height;
    int size;

}

template <typename element>
bitree<element>::bitree()
{
    root=nullptr;
    height=0;
    size=0;
}

#endif
