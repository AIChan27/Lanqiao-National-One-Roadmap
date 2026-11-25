#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 300005;
int a[MAXN];
int main()
{
    int N, max_comp=0, ans = 0;
    freopen("../Datain/P2777.datain", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N, greater<int>());
    for (int i = 0; i < N; i++)
        max_comp = max(max_comp, a[i] + i + 1);
    for (int i = 0; i < N; i++)
        if (a[i] + N >= max_comp)
            ans++;
        else
            break;
    cout << ans << "\n";
    return 0;
}