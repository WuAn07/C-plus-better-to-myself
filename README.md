

# C-plus-better-to-myself

> 记录一下自己在 C++ 上的进阶代码库

这是一个用于存放 C++ 学习过程中进阶代码的仓库，主要涵盖数据结构的手写实现、类的封装以及一些课程作业。代码会随着学习进度持续更新。

## 📖 内容概览

仓库目前主要包含以下几类内容：

### 1. 自定义数据结构（手写实现）
| 文件 | 说明 |
|------|------|
| `seqlist.cpp` / `seqlist.h` | 顺序表（Sequence List）的实现 |
| `linklist.h` | 单向链表（Linked List）的实现 |
| `bitree.h` | 二叉树（Binary Tree）的基本实现 |
| `deqlist.h` | 双端队列（Deque List）的实现 |

### 2. 类与封装
| 文件 | 说明 |
|------|------|
| `string.cpp` / `string.h` | 自我实现的 `string` 类（第一次写，后续可能会改善） |
| `Day.cpp` / `Day.h` | `Day` 类的实现，配套 Visual Studio 工程使用 |

### 3. 作业与练习
| 文件 | 说明 |
|------|------|
| `homework1.cpp` | 课程作业（2.5 启发作业最终版本） |
| `test.cpp` / `test1.cpp` / `tset.cpp` | 各模块的测试代码 |
| `思路.docx` | 作业相关的思路记录 |

### 4. 学习资料
| 文件 | 说明 |
|------|------|
| `UML类图入门讲解(2).pptx` | UML 类图入门讲解课件 |

## 🗂️ 工程文件说明

仓库根目录下包含 Visual Studio 工程文件：
- `Project_Day.vcxproj`
- `Project_Day.vcxproj.filters`
- `Project_Day.vcxproj.user`

> 如果你使用 Visual Studio 打开本仓库，可以直接双击 `.vcxproj` 文件加载工程。

## 🚀 如何使用

1. **克隆仓库**
   ```bash
   git clone https://github.com/WuAn07/C-plus-better-to-myself.git
   ```

2. **单独编译某个模块**（以顺序表为例）
   ```bash
   g++ seqlist.cpp -o seqlist
   ```

3. **使用 Visual Studio 打开**
   直接打开 `Project_Day.vcxproj` 即可加载整个工程。

## 📌 说明

- 本仓库主要用于个人学习记录，代码风格和实现方式可能随着学习深入而调整。
- 部分文件（如 `string` 类）是早期练习版本，注释或实现上可能不够完善，欢迎交流指正。
- 后续会持续补充新的数据结构和算法实现。

## 📅 更新日志

- **2026-10-21**：添加基本二叉树实现 (`bitree.h`)
- **2026-10-13**：添加单向链表实现 (`linklist.h`)
- **2026-09-18**：添加双端队列实现 (`deqlist.h`)
- **2026-09-17**：添加顺序表实现 (`seqlist.cpp` / `seqlist.h`)
- **2026-08-19**：添加 `Day` 类及 Visual Studio 工程文件
- **2026-08-17**：添加自定义 `string` 类实现

---

**如果觉得这个仓库对你有帮助，欢迎点个 Star ⭐️**
