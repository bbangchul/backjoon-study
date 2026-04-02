#include <bits/stdc++.h>
using namespace std;

void solve()
{
    while (1)
    {
        string a;
        getline(cin, a);
        if (a == ".")
            break;
        stack<char> st;
        bool isValid = true;
        for (auto c : a)
        {
            if (c == '(' || c == '[')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    isValid = false;
                    break;
                }
                st.pop();
            }
            else if (c == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty())
        {
            isValid = false;
        }
        if (isValid)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}