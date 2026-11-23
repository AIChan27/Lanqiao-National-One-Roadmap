#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;
int a[MAXN];
int main()
{
    int n, d;
    long long num = 0;
    // freopen("./Datain/P1296.datain", "r", stdin);
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int B = d + a[i];
        auto end = upper_bound(a + i+1, a + n, B);
        num+=end-a-i-1;
    }
    cout << num << endl;
    return 0;
}