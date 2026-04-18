#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int a[11], b[11];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
            ans += a[i] - b[i];
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
    {
        solve();
    }
    return 0;
}