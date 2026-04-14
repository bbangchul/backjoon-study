#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    ll m;
    cin >> n >> m;

    vector<ll> s(n), v(n);
    ll lo = 0, hi = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        lo = min(lo, s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        hi = max(hi, s[i] + m * v[i]);
    }

    function<bool(ll)> ok = [&](ll x)
    {
        ll need = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= x)
                continue;
            need += (x - s[i] + v[i] - 1) / v[i];
            if (need > m)
                return false;
        }
        return true;
    };

    ll ans = lo;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (ok(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}