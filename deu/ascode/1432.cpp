#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int m;
    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            int sum = i * i + j * j;

            int n = sqrt(sum);

            if (n <= m && n * n == sum)
            {
                cout << i << ", "
                     << j << ", "
                     << n << '\n';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}