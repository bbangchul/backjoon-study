#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<int> v(8);
    int sum = 0;
    int min = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> v[i];
        if (v[i] & 1)
        {
            sum += v[i];
            if (min == 0 || min > v[i])
                min = v[i];
        }
    }
    if (sum == 0)
    {
        cout << "-1";
    }
    else
    {
        cout << sum << '\n'
             << min;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}