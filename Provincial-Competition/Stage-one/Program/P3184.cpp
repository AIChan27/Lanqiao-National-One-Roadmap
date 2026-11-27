#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;
int a[MAXN];
using namespace std;
int main()
{
    int N, Q, A, B;
    freopen("../Datain/P3184.datain", "r", stdin);
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N);
    for (int i = 0; i < Q; i++)
    {
        cin >> A >> B;
        int start = lower_bound(a, a + N, A) - a;
        int end = upper_bound(a, a + N, B) - a;
        cout << end - start << "\n";
    }
    return 0;
}