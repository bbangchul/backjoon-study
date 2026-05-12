#include <bits/stdc++.h>
using namespace std;

void solve()
{
    for (int i = 0; i < 4; i++)
    {
        int a;
        cin >> a;
        string s = "";
        while (a > 0)
        {
            s += (a % 2) + '0';
            a /= 2;
        }
        reverse(s.begin(), s.end());

        int sl = s.length();
        while (sl < 8)
        {
            s = '0' + s;
            sl++;
        }
        cout << s;

        if (i != 3)
        {
            char dot;
            cin >> dot;
        }
    }
    cout << '\n';
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