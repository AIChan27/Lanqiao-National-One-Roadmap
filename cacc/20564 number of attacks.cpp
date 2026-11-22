#include <iostream>
using namespace std;
int main()
{
    int num = 0, sub = 0, blood = 2025, six = 67, attack[6] = {15, 10, 15, 5, 15, 7};
    num = blood / six*6;
    sub = blood % six;
    int i = 0;
    while (sub > 0)
    {
        sub-=attack[i];
        num++;
        i++;
    }
    cout << num << endl;
    return 0;
}