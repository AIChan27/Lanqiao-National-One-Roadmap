#include <iostream>
using namespace std;
int main()
{
    string name = "", str;
    // freopen("./testdata/20678 Naming the kitten.datain", "r", stdin);
    for (int i = 0; i < 6; i++)
    {
        cin >> str;
        name += str[0];
    }
    cout << name << endl;
    return 0;
}