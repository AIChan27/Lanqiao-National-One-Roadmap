# C++ 二分查找库函数用法整理

## 目录
1. 前提：序列必须有序
2. `std::binary_search`
3. `std::lower_bound`
4. `std::upper_bound`
5. `std::equal_range`
6. 如何选择
7. 完整示例
8. 自定义比较器
9. `set` / `map` 的成员函数
10. 库函数 vs 手写

---

## 1. 前提：序列必须有序

标准库二分查找函数不会自动排序。  
如果序列无序，结果未定义。

```cpp
std::vector<int> v{3, 1, 4, 1, 5};
// std::binary_search(v.begin(), v.end(), 4); // 错误！结果未定义
std::sort(v.begin(), v.end());
std::binary_search(v.begin(), v.end(), 4);     // 正确
```

这些函数都作用于前闭后开范围 `[first, last)`。

---

## 2. `std::binary_search`

只判断元素是否存在，返回 `bool`。

```cpp
bool exists = std::binary_search(v.begin(), v.end(), 30);
```

不关心位置，不返回迭代器。

---

## 3. `std::lower_bound`

返回第一个**不小于**目标值的位置。

默认升序下，即第一个 `>= value` 的位置。

```cpp
std::vector<int> v{10, 20, 30, 30, 30, 40};

auto it = std::lower_bound(v.begin(), v.end(), 30);
// it 指向第一个 30，索引为 2
```

如果所有元素都小于目标值，返回 `last`。

常见用途：
- 查找元素首次出现位置；
- 获取安全插入位置；
- 与 `upper_bound` 配合统计相等元素个数。

---

## 4. `std::upper_bound`

返回第一个**严格大于**目标值的位置。

```cpp
auto it = std::upper_bound(v.begin(), v.end(), 30);
// 在上面的 v 中，it 指向 40，索引为 5
```

---

## 5. `std::equal_range`

一次性返回相等元素的完整范围，类型为 `pair<迭代器, 迭代器>`。

```cpp
auto [beg, end] = std::equal_range(v.begin(), v.end(), 30);

int count = std::distance(beg, end); // 3
// [beg, end) 内全是 30
```

---

## 6. 如何选择

| 需求 | 应使用的函数 |
|---|---|
| 只想知道在不在 | `binary_search` |
| 找第一个 `>=` 目标值的位置 | `lower_bound` |
| 找第一个 `>` 目标值的位置 | `upper_bound` |
| 拿到所有等于目标值的范围 | `equal_range` |
| 获取目标值首次出现索引 | `lower_bound` + 距离计算 |
| 统计目标值出现次数 | `upper_bound - lower_bound` |

---

## 7. 完整示例

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{10, 20, 30, 30, 30, 40, 50};

    // 存在性
    std::cout << std::boolalpha
              << std::binary_search(v.begin(), v.end(), 30)
              << '\n'; // true

    // 第一个 >= 30 的位置
    auto lb = std::lower_bound(v.begin(), v.end(), 30);
    std::cout << "lower_bound index: "
              << (lb - v.begin()) << '\n'; // 2

    // 第一个 > 30 的位置
    auto ub = std::upper_bound(v.begin(), v.end(), 30);
    std::cout << "upper_bound index: "
              << (ub - v.begin()) << '\n'; // 5

    // 相等范围
    auto [beg, end] = std::equal_range(v.begin(), v.end(), 30);
    std::cout << "count of 30: "
              << std::distance(beg, end) << '\n'; // 3

    // 安全插入，保持有序
    v.insert(std::lower_bound(v.begin(), v.end(), 25), 25);
}
```

---

## 8. 自定义比较器

所有二分查找函数都支持自定义比较器。  
以 `lower_bound` 为例：

```cpp
std::vector<int> v{50, 40, 30, 30, 20, 10};

auto it = std::lower_bound(
    v.begin(), v.end(), 30, std::greater<int>());
// 降序序列中，返回第一个 <= 30 的位置
```

比较器语义：`lower_bound` 返回第一个使 `comp(*it, value)` 为 `false` 的位置。

---

## 9. `set` / `map` 的成员函数

对于 `std::set`、`std::map`，优先使用成员函数：

```cpp
std::set<int> s{10, 20, 30};
auto it = s.lower_bound(20); // 使用 set 自己的 lower_bound
```

成员函数通常比通用 `std::lower_bound` 更高效。

---

## 10. 库函数 vs 手写

大多数情况下直接使用标准库函数，不需要手写二分查找。

需要手写的典型场景：
- 比较逻辑非常特殊，标准库函数难以表达；
- 在非标准数据结构上实现二分；
- 教学或面试要求。

常规业务代码优先使用 `std::lower_bound` / `std::upper_bound`。