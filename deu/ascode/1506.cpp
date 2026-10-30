#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int m;
    cin >> m;

    int cnt = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            int sum = i * i + j * j;
            int n = sqrt(sum);

            if (n > m)
                break;

            if (n * n == sum)
            {
                cnt++;
            }
        }
    }

    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
