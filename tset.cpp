#include "deqlist.h"
#include <iostream>
#include <string>
using namespace std;


string read_str(string tip)
{
    string s;
    cout << tip;
    cin >> s;
    return s;
}


 //  一维菜单
 
void menu1()
{
    Deqlist<string> L;
    while(true)
    {
        cout << endl;
        cout << "===== 一维顺序表 (string) =====" << endl;
        cout << "1. 尾插" << endl;
        cout << "2. 头插" << endl;
        cout << "3. 按位插入" << endl;
        cout << "4. 尾删" << endl;
        cout << "5. 头删" << endl;
        cout << "6. 按位删除" << endl;
        cout << "7. 按值删除" << endl;
        cout << "8. 按位查找" << endl;
        cout << "9. 按值查找" << endl;
        cout << "10. 打印" << endl;
        cout << "11. 去重" << endl;
        cout << "0. 返回" << endl;

        string c = read_str("请选择: ");

        if(c == "0")
        {
            return;
        }
        else if(c == "1")
        {
            string x = read_str("请输入要尾插的值: ");
            L.push_back(x);
            L.print_deqlist();
        }
        else if(c == "2")
        {
            string x = read_str("请输入要头插的值: ");
            L.push_front(x);
            L.print_deqlist();
        }
        else if(c == "3")
        {
            string posStr = read_str("请输入插入位置: ");
            int pos = stoi(posStr);
            if(pos < 0 || (size_t)pos > L.get_size())
            {
                cout << "位置越界" << endl;
                continue;
            }
            string x = read_str("请输入要插入的值: ");
            L.insert((size_t)pos, x);
            L.print_deqlist();
        }
        else if(c == "4")
        {
            if(L.get_size() == 0)
            {
                cout << "表为空" << endl;
                continue;
            }
            cout << "删除的元素是: " << L.pop_back() << endl;
            L.print_deqlist();
        }
        else if(c == "5")
        {
            if(L.get_size() == 0)
            {
                cout << "表为空" << endl;
                continue;
            }
            cout << "删除的元素是: " << L.pop_front() << endl;
            L.print_deqlist();
        }
        else if(c == "6")
        {
            if(L.get_size() == 0)
            {
                cout << "表为空" << endl;
                continue;
            }
            string posStr = read_str("请输入要删除的下标: ");
            int pos = stoi(posStr);
            if(pos < 0 || (size_t)pos >= L.get_size())
            {
                cout << "位置越界" << endl;
                continue;
            }
            cout << "删除的元素是: " << L.erase((size_t)pos) << endl;
            L.print_deqlist();
        }
        else if(c == "7")
        {
            string x = read_str("请输入要删除的值: ");
            int idx = L.erase(x);
            if(idx == -1)
            {
                cout << "未找到" << endl;
            }
            else
            {
                cout << "已删除, 原下标 = " << idx << endl;
            }
            L.print_deqlist();
        }
        else if(c == "8")
        {
            if(L.get_size() == 0)
            {
                cout << "表为空" << endl;
                continue;
            }
            string posStr = read_str("请输入要查询的下标: ");
            int pos = stoi(posStr);
            if(pos < 0 || (size_t)pos >= L.get_size())
            {
                cout << "位置越界" << endl;
                continue;
            }
            cout << "该位置的值是: " << L.search((size_t)pos) << endl;
        }
        else if(c == "9")
        {
            string x = read_str("请输入要查询的值: ");
            int idx = L.search(x);
            if(idx == -1)
            {
                cout << "未找到" << endl;
            }
            else
            {
                cout << "首次出现在下标 " << idx << endl;
            }
        }
        else if(c == "10")
        {
            L.print_deqlist();
        }
        else if(c == "11")
        {
            L.erase_same();
            cout << "去重完成" << endl;
            L.print_deqlist();
        }
        else
        {
            cout << "输入错误，请重新输入" << endl;
        }
    }
}

 //二维菜单

void menu2()
{
    Deqlist< Deqlist<string> > M;
    while(true)
    {
        cout << endl;
        cout << "===== 二维顺序表 (string) =====" << endl;
        cout << "1. 加一行" << endl;
        cout << "2. 插入一行" << endl;
        cout << "3. 删除一行" << endl;
        cout << "4. 查看一行" << endl;
        cout << "5. 打印整个表" << endl;
        cout << "6. 修改一格" << endl;
        cout << "7. 查看一格" << endl;
        cout << "8. 查看行数" << endl;
        cout << "0. 返回" << endl;

        string c = read_str("请选择: ");

        if(c == "0")
        {
            return;
        }
        else if(c == "1")
        {
            Deqlist<string> row;
            cout << "请输入这一行的元素 (输入 stop 结束):" << endl;
            while(true)
            {
                string x = read_str("  > ");
                if(x == "stop") break;
                row.push_back(x);
            }
            M.push_back(row);
            M.print_deqlist();
        }
        else if(c == "2")
        {
            string posStr = read_str("请输入插入到第几行: ");
            int pos = stoi(posStr);
            if(pos < 0 || (size_t)pos > M.get_size())
            {
                cout << "位置越界" << endl;
                continue;
            }
            Deqlist<string> row;
            cout << "请输入这一行的元素 (输入 stop 结束):" << endl;
            while(true)
            {
                string x = read_str("  > ");
                if(x == "stop") break;
                row.push_back(x);
            }
            M.insert((size_t)pos, row);
            M.print_deqlist();
        }
        else if(c == "3")
        {
            if(M.get_size() == 0)
            {
                cout << "表为空" << endl;
                continue;
            }
            string posStr = read_str("请输入要删除的行号: ");
            int pos = stoi(posStr);
            if(pos < 0 || (size_t)pos >= M.get_size())
            {
                cout << "位置越界" << endl;
                continue;
            }
            M.erase((size_t)pos);
            M.print_deqlist();
        }
        else if(c == "4")
        {
            if(M.get_size() == 0)
            {
                cout << "表为空" << endl;
                continue;
            }
            string posStr = read_str("请输入要查看的行号: ");
            int pos = stoi(posStr);
            if(pos < 0 || (size_t)pos >= M.get_size())
            {
                cout << "位置越界" << endl;
                continue;
            }
            M[(size_t)pos].print_deqlist();
        }
        else if(c == "5")
        {
            M.print_deqlist();
        }
        else if(c == "6")
        {
            if(M.get_size() == 0)
            {
                cout << "表为空" << endl;
                continue;
            }
            string rStr = read_str("请输入行号: ");
            int r = stoi(rStr);
            if(r < 0 || (size_t)r >= M.get_size())
            {
                cout << "行越界" << endl;
                continue;
            }
            string colStr = read_str("请输入列号: ");
            int col = stoi(colStr);
            if(col < 0 || (size_t)col >= M[(size_t)r].get_size())
            {
                cout << "列越界" << endl;
                continue;
            }
            string x = read_str("请输入新值: ");
            M[(size_t)r][(size_t)col] = x;
            M.print_deqlist();
        }
        else if(c == "7")
        {
            if(M.get_size() == 0)
            {
                cout << "表为空" << endl;
                continue;
            }
            string rStr = read_str("请输入行号: ");
            int r = stoi(rStr);
            if(r < 0 || (size_t)r >= M.get_size())
            {
                cout << "行越界" << endl;
                continue;
            }
            string colStr = read_str("请输入列号: ");
            int col = stoi(colStr);
            if(col < 0 || (size_t)col >= M[(size_t)r].get_size())
            {
                cout << "列越界" << endl;
                continue;
            }
            cout << "该格的值为: " << M[(size_t)r][(size_t)col] << endl;
        }
        else if(c == "8")
        {
            cout << "当前共有 " << M.get_size() << " 行" << endl;
        }
        else
        {
            cout << "输入错误，请重新输入" << endl;
        }
    }
}


//交并集测试
// 从键盘读一个顺序表
Deqlist<string> read_list(string name)
{
    Deqlist<string> L;
    cout << endl;
    cout << "请输入顺序表 " << name << " 的元素 (输入 stop 结束):" << endl;
    while(true)
    {
        string x = read_str("  > ");
        if(x == "stop") break;
        L.push_back(x);
    }
    return L;
}

// 交并集专门测试
void test_set_both()
{
    while(true)
    {
        cout << endl;
        cout << "===== 交并集测试 (string) =====" << endl;
        cout << "说明: set_both(A, B) 之后" << endl;
        cout << "      表 A 变成 A ∩ B (交集)" << endl;
        cout << "      表 B 变成 A ∪ B (并集)" << endl;
        cout << endl;
        cout << "1. 开始测试" << endl;
        cout << "2. 自动演示 (用一组内置数据)" << endl;
        cout << "0. 返回主菜单" << endl;

        string c = read_str("请选择: ");

        if(c == "0")
        {
            return;
        }
        else if(c == "1")
        {
            // ---------- 手动输入两组数据 ----------
            Deqlist<string> A = read_list("A");
            Deqlist<string> B = read_list("B");

            // 拷贝一份原始数据，方便对比
            Deqlist<string> A_old = A;
            Deqlist<string> B_old = B;

            cout << endl;
            cout << "---------- 运算前 ----------" << endl;
            cout << "表 A: ";
            A_old.print_deqlist();
            cout << "表 B: ";
            B_old.print_deqlist();

            // 调用你自己的 set_both
            set_both(A, B);

            cout << endl;
            cout << "---------- 运算后 ----------" << endl;
            cout << "A ∩ B (存在 A 里): ";
            A.print_deqlist();
            cout << "A ∪ B (存在 B 里): ";
            B.print_deqlist();
        }
        else if(c == "2")
        {
            // ---------- 用内置数据自动演示 ----------
            Deqlist<string> A;
            Deqlist<string> B;

            // 故意放一些重复元素, 检验 set_both 的去重效果
            A.push_back("apple");
            A.push_back("banana");
            A.push_back("cherry");
            A.push_back("apple");       // 重复
            A.push_back("date");

            B.push_back("banana");
            B.push_back("cherry");
            B.push_back("fig");
            B.push_back("banana");      // 重复
            B.push_back("grape");

            cout << endl;
            cout << "---------- 演示数据 ----------" << endl;
            cout << "表 A: ";
            A.print_deqlist();
            cout << "表 B: ";
            B.print_deqlist();

            set_both(A, B);

            cout << endl;
            cout << "---------- 运算结果 ----------" << endl;
            cout << "A ∩ B (存在 A 里): ";
            A.print_deqlist();
            cout << "A ∪ B (存在 B 里): ";
            B.print_deqlist();

            cout << endl;
            cout << "解释: A 与 B 的公共元素是 banana、cherry," << endl;
            cout << "      合在一起的所有元素是 apple、banana、cherry、date、fig、grape。" << endl;
        }
        else
        {
            cout << "输入错误，请重新输入" << endl;
        }
    }
}

/* ============================================================
 *                      五、主函数
 * ============================================================ */
int main()
{
    string s;
    while(true)
    {
        cout << endl;
        cout << "请输入要创建的表格:" << endl;
        cout << "1. 一维顺序表 (string)" << endl;
        cout << "2. 二维顺序表 (string)" << endl;
        cout << "3. 测试两个顺序表的交集/并集" << endl;
        cout << "0. 退出" << endl;

        cin >> s;

        if(s == "1")
        {
            menu1();
        }
        else if(s == "2")
        {
            menu2();
        }
        else if(s == "3")
        {
            test_set_both();
        }
        else if(s == "0")
        {
            cout << "再见" << endl;
            return 0;
        }
        else
        {
            cout << "输入错误，请重新输入" << endl;
        }
    }

    return 0;
}





// #include"deqlist.h"
// #include<iostream>

// using namespace std;

// int main()
// {
    // Deqlist<int>list1;
    // Deqlist<int>list2;
    // for(int i=0;i<5;++i)
    // {
    //     list1.push_back(i);
    // }
    // for(int i=0;i<4;++i)
    // {
    //     list2.push_back(i*2);
    // }
    // list1.print_deqlist();
    // list2.print_deqlist();
    // set_both(list1,list2);
    // list1.print_deqlist();
    // list2.print_deqlist();

    // Deqlist<Deqlist<int>>list3;
    // list3.push_back(list1);
    // list3.push_back(list2);
    // list3.print_deqlist();
    // cout<<list3[0][0]<<"  "<<list3[0][1]<<endl;
    // list3.print_deqlist();
    // for(auto &x : list1)
    // {
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    //  list1.print_deqlist();
    //for(size_t i=0;i<2;++i)cout<<list3[i]<<" ";
    // cout<<"二维顺序表的打印"<<endl;
    // list3.print_deqlist();
//     return 0;
// }