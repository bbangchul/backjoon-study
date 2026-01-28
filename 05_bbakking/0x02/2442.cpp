#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << ' ';
        }
        int star = i * 2 + 1;
        for (int j = 0; j < star; j++)
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