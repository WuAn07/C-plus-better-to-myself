#include <iostream>
#include <string>
#include "bitree.h"

using namespace std;

void show_menu() {
    cout << "\n========= 二叉树测试菜单 =========\n";
    cout << " 1. 设置根节点 (会清空旧树)\n";
    cout << " 2. 插入左孩子\n";
    cout << " 3. 插入右孩子\n";
    cout << " 4. 先序遍历 (递归)\n";
    cout << " 5. 中序遍历 (递归)\n";
    cout << " 6. 后序遍历 (递归)\n";
    cout << " 7. 层次遍历\n";
    cout << " 8. 非递归前序遍历\n";
    cout << " 9. 打印叶子节点 (层次顺序)\n";
    cout << "10. 查找节点\n";
    cout << "11. 获取树的高度\n";
    cout << "12. 获取节点数\n";
    cout << "13. 判空\n";
    cout << "14. 清空整棵树\n";
    cout << " 0. 退出\n";
    cout << "==================================\n";
    cout << "请选择: ";
}

int main() {
    bitree<string> t;
    int choice;
    while (true) {
        show_menu();
        if (!(cin >> choice)) break;
        switch (choice) {
            case 1: {
                string x;
                cout << "输入根节点值: ";
                cin >> x;
                t.set_root(x);
                cout << "设置成功,当前节点数: " << t.get_size() << endl;
                break;
            }
            case 2: {
                string p, c;
                cout << "输入父节点值: "; cin >> p;
                cout << "输入左孩子值: "; cin >> c;
                if (t.insert_lchild(p, c))
                    cout << "插入成功,当前节点数: " << t.get_size() << endl;
                else
                    cout << "插入失败(父节点不存在或左孩子已存在)" << endl;
                break;
            }
            case 3: {
                string p, c;
                cout << "输入父节点值: "; cin >> p;
                cout << "输入右孩子值: "; cin >> c;
                if (t.insert_rchild(p, c))
                    cout << "插入成功,当前节点数: " << t.get_size() << endl;
                else
                    cout << "插入失败(父节点不存在或右孩子已存在)" << endl;
                break;
            }
            case 4:
                cout << "先序遍历: ";
                t.preorder(t.get_root());
                cout << endl;
                break;
            case 5:
                cout << "中序遍历: ";
                t.inorder(t.get_root());
                cout << endl;
                break;
            case 6:
                cout << "后序遍历: ";
                t.postorder(t.get_root());
                cout << endl;
                break;
            case 7:
                cout << "层次遍历: ";
                t.levelorder(t.get_root());
                cout << endl;
                break;
            case 8:
                cout << "非递归前序遍历: ";
                t.no_dfs_preorder(t.get_root());
                cout << endl;
                break;
            case 9:
                cout << "叶子节点: ";
                t.order_leaves(t.get_root());
                cout << endl;
                break;
            case 10: {
                string target;
                cout << "输入要查找的值: "; cin >> target;
                auto* p = t.find(t.get_root(), target);
                if (p) cout << "找到节点: " << p->data << endl;
                else cout << "未找到" << endl;
                break;
            }
            case 11:
                cout << "树的高度: " << t.get_height(t.get_root()) << endl;
                break;
            case 12:
                cout << "节点数: " << t.get_size() << endl;
                break;
            case 13:
                cout << (t.empty() ? "树为空" : "树非空") << endl;
                break;
            case 14:
                t.clear(t.get_root());
                cout << "清空成功" << endl;
                break;
            case 0:
                cout << "退出" << endl;
                return 0;
            default:
                cout << "无效选项" << endl;
        }
    }
    return 0;
}