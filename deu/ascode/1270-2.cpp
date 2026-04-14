#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int si;
    int vi;
} s;

void solve()
{
    s a[101] = {0};
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i].si;
    for (int i = 0; i < n; i++)
        cin >> a[i].vi;

    while (m--)
    {
        int minval = a[0].si;
        int minidx = 0;
        for (int i = 1; i < n; i++)
        {
            int v = a[i].si;
            if (v < minval)
            {
                minval = v;
                minidx = i;
            }
        };
        a[minidx].si += a[minidx].vi;
    }

    int ans = a[0].si;
    for (int i = 1; i < n; i++)
    {
        int v = a[i].si;
        if (v < ans)
            ans = v;
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