#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    list<char> ans = {};
    auto p = ans.end();

    for (auto c : s)
    {
        if (c == '<')
        {
            if (p != ans.begin())
                p--;
        }
        else if (c == '>')
        {
            if (p != ans.end())
                p++;
        }
        else if (c == '-')
        {
            if (p != ans.begin())
            {
                p--;
                p = ans.erase(p);
            }
        }
        else
        {
            ans.insert(p, c);
        }
    }
    for (auto c : ans)
        cout << c;
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}