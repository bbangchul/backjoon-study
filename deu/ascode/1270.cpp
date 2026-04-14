#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int si;
    int vi;
    int w;
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
        int minval = a[0].si + a[0].w * a[0].vi;
        int minidx = 0;
        for (int i = 1; i < n; i++)
        {
            int v = a[i].si + a[i].w * a[i].vi;
            if (v < minval)
            {
                minval = v;
                minidx = i;
            }
        }
        a[minidx].w++;
    }

    int ans = a[0].si + a[0].w * a[0].vi;
    for (int i = 1; i < n; i++)
    {
        int v = a[i].si + a[i].w * a[i].vi;
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