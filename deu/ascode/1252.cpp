#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    for (int i = 0; i < 4; i++)
    {
        int num = 0;

        for (int j = 0; j < 8; j++)
        {
            num = num * 2 + (s[i * 8 + j] - '0');
        }

        if (i > 0)
            cout << '.';

        cout << num;
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}