#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[1001] = {0};
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (!arr[a])
        {
            arr[a]++;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        if (arr[i])
        {
            cout << i << ' ';
        }
    }
    cout << '\n';
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