#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a;
    cin >> a;

    stack<char> st;
    bool isValid = true;
    for (auto c : a)
    {
        if (c == '(' || c == '[' || c == '{')
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
        else if (c == '}')
        {
            if (st.empty() || st.top() != '{')
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
        cout << "Good!\n";
    }
    else
    {
        cout << "Retry...\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
}