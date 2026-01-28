#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    if (a == b || b - a == 1)
        cout << 0;
    else
    {
        cout << b - a - 1 << "\n";
        for (long long i = a + 1; i < b; i++)
            cout << i << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}