#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;

    if (n > m)
        swap(n, m);

    ll cnt = m - n + 1;
    ll sum = (n + m) * cnt / 2;

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