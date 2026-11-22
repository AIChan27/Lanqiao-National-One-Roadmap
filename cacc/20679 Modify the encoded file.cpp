#include <iostream>
using namespace std;
int main()
{
    string str;
    // freopen("./testdata/Modify the encoded file.datain", "r", stdin);
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        // a-z:97-122
        // 0-9:48-57
        if (str[i] >= 97 && str[i] <= 122)
            // cout << str[i] << endl;
            str[i] = 'L';
        else if (str[i] >= 48 && str[i] <= 157)
            // cout << str[i] << endl;
            str[i] = 'Q';
    }
    cout << str << endl;
    return 0;
}