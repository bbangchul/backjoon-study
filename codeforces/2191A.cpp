#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        pos[a[i]] = i;
    }

    bool ok = true;

    for (int x = 1; x < n; x++)
    {
        if ((pos[x] % 2) == (pos[x + 1] % 2))
        {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
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