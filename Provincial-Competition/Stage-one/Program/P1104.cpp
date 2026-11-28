#include <iostream>
#include <algorithm>

using namespace std;

struct Student
{
    string s;
    int id;
    int y;
    int m;
    int d;

    bool operator<(const Student &other) const
    {
        // 年龄从大到小同学的姓名
        if (y != other.y)
            return y < other.y;
        else
        {
            if (m != other.m)
                return m < other.m;
            else
            {
                if (d != other.d)
                    return d < other.d;
                else
                // 如果有两个同学年龄相同，输入靠后的同学先输出
                    return id > other.id;
            }
        }
    }
};

const int MAXN = 105;
Student a[MAXN];

int main()
{
    int n;
    freopen("../Datain/P1104.datain", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].s >> a[i].y >> a[i].m >> a[i].d;
        a[i].id = i + 1;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i].s << "\n";
    return 0;
}