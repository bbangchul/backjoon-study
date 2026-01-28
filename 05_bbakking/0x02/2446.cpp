#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int star = n * 2 - 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j < star; j++)
        {
            cout << '*';
        }
        star -= 2;
        cout << '\n';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j < i * 2 + 1; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}