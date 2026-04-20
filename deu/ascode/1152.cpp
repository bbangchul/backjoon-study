#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int len = 1;
    int cnt = 0;
    while (n != 1)
    {
        if (n % 2 == 1)
        {
            n = 3 * n + 1;
        }
        else
        {
            n /= 2;
            cnt++;
        }
        len++;
    }
    cout << len << ' ' << cnt << '\n';
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