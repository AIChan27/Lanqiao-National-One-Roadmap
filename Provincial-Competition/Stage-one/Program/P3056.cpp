#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    int num = 0;
    string kuohao = "";
    stack<char> st;
    freopen("../Datain/P3056.datain", "r", stdin);
    cin >> kuohao;
    for (int i = 0; i < kuohao.length(); i++)
    {
        if (st.empty())
            st.push(kuohao[i]);
        else
        {
            char sttop = st.top();
            if (sttop == '(' && kuohao[i] == ')')
                st.pop();
            else
                st.push(kuohao[i]);
        }
    }
    int cycle = st.size() / 2;
    for (int i = 0; i < cycle; i++)
    {
        char first = st.top();
        st.pop();
        char second = st.top();
        st.pop();
        if (first == second)
            num++;
        else
            num += 2;
    }
    cout << num << "\n";
    return 0;
}