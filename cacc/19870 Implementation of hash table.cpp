#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    char op;
    int num, x;
    unordered_set<int> hash_list;
    freopen("./testdata/19870 Implementation of hash table.datain", "r", stdin);
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> op >> x;
        if (op == 'I')
            hash_list.insert(x);
        else if (op == 'Q')
        {
            if (hash_list.count(x))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}