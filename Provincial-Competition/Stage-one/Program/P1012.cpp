#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 25;
string a[MAXN];

int main()
{
    int N;
    freopen("../Datain/P1012.datain", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N, [](const string &a, const string &b)
         { return a + b > b + a; });
    for (int i = 0; i < N; i++)
        cout << a[i];
    return 0;
}