#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v(5);
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    cout << sum / 5 << '\n'
         << v[2];
}

int main()
{
    ios::sync_with_stdio;
    cin.tie(0);
    solve();
}