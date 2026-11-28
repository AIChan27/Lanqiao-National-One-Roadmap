# C++ 结构体 (struct) 竞赛使用指南

## 🎯 核心结论：不要用 `typedef`
在现代 C++（尤其是算法竞赛中），**不需要也不推荐**使用 `typedef` 来为结构体起别名。
直接使用 `struct` 定义，C++ 编译器会自动将其作为类型名使用。

---

## 1. 为什么不用 `typedef`？（C 与 C++ 的区别）
*   **C 语言**：定义 `struct Node {...};` 后，声明变量必须写 `struct Node n;`。为了少打字，C 程序员习惯用 `typedef struct Node {...} Node;`。
*   **C++**：编译器自动将结构体名提升为类型名。直接写 `struct Node {...};`，以后直接写 `Node n;` 即可。

---

## 2. 算法竞赛中的三种核心用法

### ① 基础用法：打包多个变量
适合存坐标 `(x, y)`、图论的边 `(u, v, w)` 等。
```cpp
struct Point {
    int x;
    int y;
};

int main() {
    Point p1;
    p1.x = 1; p1.y = 2;
    
    // C++11 以后支持直接列表初始化
    Point p2 = {3, 4}; 
    return 0;
}
```

### ② 进阶神技：写构造函数（防 WA 必备）
- **坑点：** 在函数内部（局部）定义结构体数组，如果不初始化，里面的变量会全是随机乱码（系统垃圾值），极易导致莫名 `WA`。
- **解法：** 写一个无参构造函数，自动清零。

```cpp
struct Edge {
    int to, weight;
    
    // 无参构造函数：创建时自动全为 0
    Edge() { to = 0; weight = 0; }
    
    // 带参构造函数：方便直接传值
    Edge(int t, int w) { to = t; weight = w; }
};

Edge e = Edge(5, 10); // 直接用带参构造
```

### ③ 进阶神技：重载运算符（配合 sort 排序）
遇到多关键字排序时，可以直接把比较规则写在结构体内部，省去写单独的 `cmp` 函数。

```cpp
struct Student {
    int score;
    int id;
    
    // 重载小于号：按 score 降序，score 相同则按 id 升序
    bool operator<(const Student& other) const {
        if (score != other.score) return score > other.score;
        return id < other.id;
    }
};

// 之后直接调用：sort(a, a + N); 即可自动按上述规则排序
```

---

## 3. 如果非要起别名，用 `using` 代替 `typedef`
现代 C++ 推荐使用 `using` 定义类型别名，语义更清晰：

```cpp
struct Node {
    int data;
};
using NodeAlias = Node; // 推荐
```

---

## 4. 结构体 (struct) vs 类 (class)
- 两者在 C++ 中极度相似，几乎只有一点区别：
  1. struct：成员默认是 public（公开的）。
  2. class：成员默认是 private（私有的）。
- 竞赛场景：90% 以上的情况用 struct，因为我们只需把数据打包在一起快速访问，不需要企业级开发那种面向对象的封装。
