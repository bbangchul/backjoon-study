#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;

    ll cnt = m - n + 1;
    ll a = n + m;
    ll b = cnt;

    if (a % 2 == 0)
        a /= 2;
    else
        b /= 2;

    ll sum = a * b;

    cout << sum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}