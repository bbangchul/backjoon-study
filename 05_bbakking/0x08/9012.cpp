#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    bool isValid = true;
    for (auto c : s)
    {
        if (c == '(')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                isValid = false;
                break;
            }
            st.pop();
        }
    }

    if (st.empty() && isValid)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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