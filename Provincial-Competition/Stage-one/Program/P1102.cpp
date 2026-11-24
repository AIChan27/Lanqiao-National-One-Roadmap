#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
int a[MAXN]; 
int main()
{
    int N, C;
    long long num = 0;
    freopen("./Datain/P1102.datain", "r", stdin);
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N);
    for (int i = 0; i < N - 1; i++)
    {
        int B = C + a[i];
        auto first = lower_bound(a + i, a + N, B);
        auto end = upper_bound(a + i, a + N, B);
        num += (end - first);
    }
    cout << num << endl;
    return 0;
}