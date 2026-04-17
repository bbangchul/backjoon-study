#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    int a[55];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cut = a[k - 1];
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= cut && a[i] > 0)
            cnt++;
    }

    cout << cnt << '\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}