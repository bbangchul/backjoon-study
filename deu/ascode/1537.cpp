#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int MOD = 100000007;
    int n, r;

    cin >> n >> r;

    vector<int> dp(r + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j >= 1; j--)
        {

            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }

    cout << dp[r] << '\n';
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
