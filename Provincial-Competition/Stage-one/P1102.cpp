#include <iostream>
using namespace std;
int sub[200001];
int main()
{
    int N, C, a, ai = 1, num = 0;
    // freopen("./Datain/P1102.datain", "r", stdin);
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        sub[a]++;
    }
    while (N > 1)
    {
        while (sub[ai] == 0)
            ai++;
        N -= sub[ai];
        if (sub[ai + C] != 0)
        {
            num += sub[ai];
            ai++;
        }
    }
    cout << num << endl;
    return 0;
}