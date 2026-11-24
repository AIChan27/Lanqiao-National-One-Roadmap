#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 3005;
const int m_max = 0x3f3f3f3f;
int a[MAXN];
int main()
{
    int n, m, min = 0;
    // freopen("../Datain/P1614.datain", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    min = m_max;
    for (int i = 0; i <= (n - m); i++)
    {
        int sum = a[i];
        for (int j = i + 1; j < (i + m); j++)
            sum += a[j];
        if (min > sum)
            min = sum;
    }
    cout << min << endl;
    return 0;
}