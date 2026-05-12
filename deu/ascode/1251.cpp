#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    int sl = s.length();
    int sum = 0;
    for (int i = 0; i < sl; i++)
    {
        sum += (s[i] - '0') * pow(2, sl - 1 - i);
    }
    cout << sum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}