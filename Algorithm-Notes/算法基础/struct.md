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