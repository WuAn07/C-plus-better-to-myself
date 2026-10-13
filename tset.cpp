#include <iostream>
#include "Linklist.h"  // 或者把代码放在这里
using namespace std;

Linklist<int>* lst = nullptr;

void show_menu() {
    cout << "\n========= 单链表测试菜单 =========" << endl;
    cout << " 1. 默认构造空链表" << endl;
    cout << " 2. 数组构造链表" << endl;
    cout << " 3. 求链表长度" << endl;
    cout << " 4. 按位取元素 get_data" << endl;
    cout << " 5. 按位取指针 get_point" << endl;
    cout << " 6. 头插 push_front" << endl;
    cout << " 7. 按位插入 insert" << endl;
    cout << " 8. 按位查找 find(i)" << endl;
    cout << " 9. 按值查找 find(d)" << endl;
    cout << "10. 按位删除 erase(n)" << endl;
    cout << "11. 按值删除 erase(d)" << endl;
    cout << "12. 打印链表" << endl;
    cout << " 0. 退出（释放内存）" << endl;
    cout << "=================================" << endl;
    cout << "请输入你的选择：";
}

int main() {
    int choice;
    while (true) {
        show_menu();
        cin >> choice;
        switch (choice) {
        case 1: {
            delete lst;
            lst = new Linklist<int>();
            cout << "已创建空链表" << endl;
            break;
        }
        case 2: {
            int n;
            cout << "请输入数组长度：";
            cin >> n;
            if (n <= 0) { cout << "长度必须>0" << endl; break; }
            int* a = new int[n];
            cout << "请输入" << n << "个整数：";
            for (int i = 0; i < n; ++i) cin >> a[i];
            delete lst;
            lst = new Linklist<int>(a, n);
            delete[] a;
            cout << "构造完成" << endl;
            break;
        }
        case 3: {
            if (!lst) { cout << "请先创建链表" << endl; break; }
            cout << "链表长度：" << lst->get_length() << endl;
            break;
        }
        case 4: {
            if (!lst) { cout << "请先创建链表" << endl; break; }
            size_t n;
            cout << "请输入位置 n：";
            cin >> n;
            if (n < 1 || n > lst->get_length()) { cout << "位置非法" << endl; break; }
            cout << "第" << n << "个元素：" << lst->get_data(n) << endl;
            break;
        }
        case 5: {
            if (!lst) { cout << "请先创建链表" << endl; break; }
            size_t i;
            cout << "请输入位置 i：";
            cin >> i;
            if (i < 1 || i > lst->get_length()) { cout << "位置非法" << endl; break; }
            node<int>* p = lst->get_point(i);
            cout << "第" << i << "个节点的数据：" << p->data << endl;
            break;
        }
        case 6: {
            if (!lst) { cout << "请先创建链表" << endl; break; }
            int d;
            cout << "请输入头插的值：";
            cin >> d;
            lst->push_front(d);
            cout << "头插成功" << endl;
            break;
        }
        case 7: {
            if (!lst) { cout << "请先创建链表" << endl; break; }
            size_t n; int d;
            cout << "请输入插入位置 n 和值 d：";
            cin >> n >> d;
            if (n < 1 || n > lst->get_length() + 1) { cout << "位置非法" << endl; break; }
            lst->insert(n, d);
            cout << "插入成功" << endl;
            break;
        }
        case 8: {
            if (!lst) { cout << "请先创建链表" << endl; break; }
            size_t i;
            cout << "请输入位置 i：";
            cin >> i;
            if (i < 1 || i > lst->get_length()) { cout << "位置非法" << endl; break; }
            cout << "第" << i << "个元素：" << lst->find(i) << endl;
            break;
        }
        case 9: {
            if (!lst) { cout << "请先创建链表" << endl; break; }
            int d;
            cout << "请输入查找的值 d：";
            cin >> d;
            size_t pos = lst->find(d);
            if (pos == 0) cout << "未找到" << endl;
            else cout << "找到，位置为：" << pos << endl;
            break;
        }
        case 10: {
            if (!lst) { cout << "请先创建链表" << endl; break; }
            size_t n;
            cout << "请输入删除位置 n：";
            cin >> n;
            if (n < 1 || n > lst->get_length()) { cout << "位置非法" << endl; break; }
            int re = lst->erase(n);
            cout << "已删除第" << n << "个元素，值为：" << re << endl;
            break;
        }
        case 11: {
            if (!lst) { cout << "请先创建链表" << endl; break; }
            int d;
            cout << "请输入要删除的值 d：";
            cin >> d;
            size_t pos = lst->erase(d);
            if (pos == 0) cout << "未找到该值，删除失败" << endl;
            else cout << "已删除值 " << d << "，位置为：" << pos << endl;
            break;
        }
        case 12: {
            if (!lst) { cout << "请先创建链表" << endl; break; }
            cout << "当前链表：";
            lst->print_list();
            break;
        }
        case 0: {
            delete lst;
            lst = nullptr;
            cout << "已释放链表，程序退出。" << endl;
            return 0;
        }
        default:
            cout << "无效选项，请重新输入" << endl;
        }
    }
}