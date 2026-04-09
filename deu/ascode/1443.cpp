#include <bits/stdc++.h>
using namespace std;

int collatzLength(long long n)
{
    int len = 1;
    while (n != 1)
    {
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
        len++;
    }
    return len;
}

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int start = min(a, b);
        int end = max(a, b);

        int bestN = start;
        int bestLen = 0;

        for (int n = start; n <= end; n++)
        {
            int len = collatzLength(n);
            if (len > bestLen)
            {
                bestLen = len;
                bestN = n;
            }
        }

        cout << bestN << ' ' << bestLen << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}