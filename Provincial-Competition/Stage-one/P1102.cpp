// 排序 + 二分查找
#include <iostream>
#include <algorithm>
using namespace std;
int sub[200001];
int main()
{
    int N, C;
    long long num = 0;
    freopen("./Datain/P1102.datain", "r", stdin);
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> sub[i];
    sort(sub, sub + N);
    int i = 0;
    while (N > 1)
    {
        int B = C - sub[i];
    }
    cout << num << endl;
    return 0;
}