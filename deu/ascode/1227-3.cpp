#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int arr[10001];
    int n, start = 0, last = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int best = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum >= best)
        {
            best = sum;
            start = i;
            last = n - i;
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
