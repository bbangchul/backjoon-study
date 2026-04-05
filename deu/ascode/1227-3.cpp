#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; ++i)
    {
        arr[i] += arr[i - 1];
    }

    int best = arr[0];
    int start = 0, last = 0;

    int mn = 0;
    int mn_idx = -1;

    for (int i = 0; i < n; ++i)
    {
        int cur = arr[i] - mn;

        if (cur > best)
        {
            best = cur;
            start = mn_idx + 1;
            last = i;
        }

        if (arr[i] <= mn)
        {
            mn = arr[i];
            mn_idx = i;
        }
    }

    cout << start + 1 << " " << last + 1 << " " << best << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}