# C++ `std::sort` 用法整理

## 目录
1. 头文件与函数原型
2. 基本用法：升序
3. 降序排序
4. 排序数组
5. 只排序一部分
6. 排序字符串
7. 自定义结构体排序
8. 多关键字排序
9. 函数对象与普通函数
10. 排序 `pair`
11. 稳定排序：`std::stable_sort`
12. 哪些容器不能直接用 `std::sort`
13. 比较器必须满足严格弱序
14. 用法速查表
15. 完整示例

---

## 1. 头文件与函数原型

```cpp
#include <algorithm>

// 默认升序
template<class RandomIt>
void sort(RandomIt first, RandomIt last);

// 自定义比较器
template<class RandomIt, class Compare>
void sort(RandomIt first, RandomIt last, Compare comp);
```

范围是前闭后开：`[first, last)`。

`std::sort` 要求**随机访问迭代器**，通常用于 `std::vector`、`std::array`、普通数组、`std::string` 等。

---

## 2. 基本用法：升序

```cpp
#include <algorithm>
#include <vector>

std::vector<int> v{3, 1, 4, 1, 5};
std::sort(v.begin(), v.end());
// v: 1 1 3 4 5
```

默认使用 `operator<`，得到升序（非递减）排列。

---

## 3. 降序排序

```cpp
#include <functional>

std::sort(v.begin(), v.end(), std::greater<int>());

// 或 Lambda
std::sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;   // 前一个应排在前面时返回 true
});
```

---

## 4. 排序数组

```cpp
int arr[] = {3, 1, 4, 1, 5};
std::sort(arr, arr + 5);   // 注意是 arr + 5，不是 arr + 4
```

也可以写：

```cpp
std::sort(std::begin(arr), std::end(arr));
```

---

## 5. 只排序一部分

```cpp
std::vector<int> v{5, 4, 3, 2, 1};
std::sort(v.begin(), v.begin() + 3); // 只排前 3 个元素
```

---

## 6. 排序字符串

```cpp
std::string s = "cba";
std::sort(s.begin(), s.end()); // "abc"

std::sort(s.begin(), s.end(), std::greater<char>()); // "cba"
```

---

## 7. 自定义结构体排序

```cpp
struct Student {
    std::string name;
    int score;
    int id;
};

std::vector<Student> st{
    {"Tom", 90, 2},
    {"Amy", 95, 1},
    {"Bob", 90, 3}
};

// 按分数降序
std::sort(st.begin(), st.end(),
    [](const Student& a, const Student& b) {
        return a.score > b.score;
    });
```

比较器参数建议使用 `const T&`，避免拷贝。

---

## 8. 多关键字排序

思路：先比较第一关键字；相等时再比较第二关键字。

```cpp
std::sort(st.begin(), st.end(),
    [](const Student& a, const Student& b) {
        if (a.score != b.score) return a.score > b.score; // 分数降序
        if (a.id != b.id)       return a.id < b.id;       // id 升序
        return a.name < b.name;                           // 姓名升序
    });
```

---

## 9. 函数对象与普通函数

```cpp
bool cmpDesc(int a, int b) {
    return a > b;
}
std::sort(v.begin(), v.end(), cmpDesc);

struct CmpByAbs {
    bool operator()(int a, int b) const {
        return std::abs(a) < std::abs(b);
    }
};
std::sort(v.begin(), v.end(), CmpByAbs{});
```

简单场景优先用 Lambda；需要复用比较规则时用函数对象或普通函数。

---

## 10. 排序 `pair`

`std::pair` 默认先按 `first` 升序，再按 `second` 升序。

```cpp
std::vector<std::pair<int, std::string>> vp{
    {2, "b"}, {1, "a"}, {2, "a"}
};
std::sort(vp.begin(), vp.end());
// (1,"a"), (2,"a"), (2,"b")
```

---

## 11. 稳定排序：`std::stable_sort`

`std::sort` 是**不稳定排序**：相等元素的相对顺序不保证保留。

需要稳定排序时使用：

```cpp
std::stable_sort(st.begin(), st.end(),
    [](const Student& a, const Student& b) {
        return a.score > b.score;
    });
```

---

## 12. 哪些容器不能直接用 `std::sort`

`std::sort` 需要随机访问迭代器，所以 `std::list`、`std::forward_list` 不能直接用：

```cpp
std::list<int> lst{3, 1, 2};
// std::sort(lst.begin(), lst.end()); // 错误
lst.sort();                           // 正确
```

`std::set` / `std::map` 本身有序，通常不需要排序。  
`std::unordered_map` / `std::unordered_set` 无序，如需排序可先拷贝到 `vector`。

---

## 13. 比较器必须满足严格弱序

比较器必须满足严格弱序，否则行为未定义。

正确写法：

```cpp
return a < b;
return a > b;
```

错误写法：

```cpp
return a <= b;
return a >= b;
```

关键规则：**两个元素相等时，比较器必须返回 `false`。**

---

## 14. 用法速查表

| 需求 | 写法 |
|---|---|
| vector 升序 | `std::sort(v.begin(), v.end());` |
| vector 降序 | `std::sort(v.begin(), v.end(), std::greater<int>());` |
| 数组升序 | `std::sort(arr, arr + n);` |
| 只排前 k 个 | `std::sort(v.begin(), v.begin() + k);` |
| 结构体多关键字 | Lambda + `if` 比较 |
| 保持相等元素原序 | `std::stable_sort(...)` |
| list 排序 | `lst.sort();` |
| 比较器规则 | 相等必须返回 `false` |

---

## 15. 完整示例

```cpp
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int score;
    int id;
};

int main() {
    std::vector<int> v{3, 1, 4, 1, 5};
    std::sort(v.begin(), v.end());                       // 升序
    std::sort(v.begin(), v.end(), std::greater<int>());  // 降序

    int arr[] = {3, 1, 4, 1, 5};
    std::sort(arr, arr + 5);

    std::vector<Student> st{
        {"Tom", 90, 2},
        {"Amy", 95, 1},
        {"Bob", 90, 3}
    };

    std::sort(st.begin(), st.end(),
        [](const Student& a, const Student& b) {
            if (a.score != b.score) return a.score > b.score;
            return a.id < b.id;
        });

    for (const auto& s : st)
        std::cout << s.name << ' ' << s.score << ' ' << s.id << '\n';
}
```