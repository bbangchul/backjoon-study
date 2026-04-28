#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int ans = 0;

    sort(v.begin(), v.end());

    for (int i = n - 1; i >= 2; i--)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            for (int m = j - 1; m >= 0; m--)
            {
                int a = v[m];
                int b = v[j];
                int c = v[i];

                if (a + b > c)
                {
                    ans = a + b + c;
                    cout << ans << '\n';
                    return;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}