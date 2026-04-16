#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long d1 = b - a;
    long long d2 = c - b;
    long long d3 = d - c;

    if (d1 == d2 && d2 == d3 && d1 != 0)
    {
        cout << "AS\n";
        return;
    }

    bool isGS = false;
    if (a != 0 && b != 0 && c != 0)
    {
        if (b % a == 0 && c % b == 0 && d % c == 0)
        {
            long long r1 = b / a;
            long long r2 = c / b;
            long long r3 = d / c;
            if (r1 == r2 && r2 == r3 && r1 != 1)
            {
                isGS = true;
            }
        }
    }

    if (isGS)
    {
        cout << "GS\n";
        return;
    }

    if ((d2 - d1) == (d3 - d2) && (d2 - d1) != 0)
    {
        cout << "OS\n";
        return;
    }

    cout << "Others\n";
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