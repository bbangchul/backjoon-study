#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << '*';
        for (int j = 1; j <= 2 * (n - i); j++)
            cout << ' ';
        for (int j = 1; j <= i; j++)
            cout << '*';
        cout << "\n";
    }

    for (int j = 1; j <= 2 * n; j++)
        cout << '*';
    cout << "\n";

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << '*';
        for (int j = 1; j <= 2 * i; j++)
            cout << ' ';
        for (int j = 1; j <= n - i; j++)
            cout << '*';
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
// 1 8 1
// 2 6 2