#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int id = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        int star = (id - 1) * 2 + 1;
        for (int j = 0; j < star; j++)
        {
            cout << '*';
        }
        id--;

        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}