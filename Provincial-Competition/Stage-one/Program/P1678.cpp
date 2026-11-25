#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int a[MAXN];
int main()
{
    int m, n, temp_b;
    long long min_sum = 0;
    // freopen("../Datain/P1678.datain", "r", stdin);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a, a + m);
    for (int i = 0; i < n; i++)
    {
        cin >> temp_b;
        int index = upper_bound(a, a + m, temp_b) - a;
        if (index == 0)
            min_sum += a[0] - temp_b;
        else if (index == m)
            min_sum += temp_b - a[m - 1];
        else
            min_sum += min((temp_b - a[index - 1]), (a[index] - temp_b));
    }
    cout << min_sum << endl;
    return 0;
}