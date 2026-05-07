#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200;
int n, test, k[MAX_N];
int kk[MAX_N * MAX_N];

bool Found(int m)
{
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            if (binary_search(kk, kk + n * n, m - k[a] - k[b]))
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> test;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }

    for (int c = 0; c < n; c++)
    {
        for (int d = 0; d < n; d++)
        {
            kk[c * n + d] = k[c] + k[d];
        }
    }
    sort(kk, kk + n * n);
    while (test--)
    {
        int m;
        cin >> m;

        if (Found(m))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
