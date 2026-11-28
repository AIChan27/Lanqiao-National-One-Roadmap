#include <iostream>
#include <algorithm>
using namespace std;
struct Student
{
    int id;
    int Chinese;
    int Math;
    int English;
    int sum;

    // 如果两个同学总分和语文成绩都相同，那么规定学号小的同学排在前面
    bool operator<(const Student &other) const
    {
        // 先按总分从高到低排序。
        if (sum != other.sum)
            return sum > other.sum;
        else
            // 如果两个同学总分相同，再按语文成绩从高到低排序。
            if (Chinese != other.Chinese)
                return Chinese > other.Chinese;
            else
                // 如果两个同学总分和语文成绩都相同，那么规定学号小的同学排在前面
                return id < other.id;
    }
};
const int MAXN = 305;
Student a[MAXN];
int main()
{
    int n;
    freopen("../Datain/P1093.datain", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i].id = i + 1;
        cin >> a[i].Chinese >> a[i].Math >> a[i].English;
        a[i].sum = a[i].Chinese + a[i].Math + a[i].English;
    }
    sort(a, a + n);
    for (int i = 0; i < 5; i++)
        cout << a[i].id << " " << a[i].sum << endl;
    return 0;
}