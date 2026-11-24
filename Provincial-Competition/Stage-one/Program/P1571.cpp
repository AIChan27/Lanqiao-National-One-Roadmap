#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int a[MAXN];
int b[MAXN];
int main()
{
    int n, m;
    bool firstOut = true;
    // freopen("./Datain/P1571.datain", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(b, b + m);
    for (int i = 0; i < n; i++)
    {
        if (binary_search(b, b + m, a[i]))
        {
            if (!firstOut)
                cout << " ";
            cout << a[i];
            firstOut = false;
        }
    }
    cout << "\n";
    return 0;
}