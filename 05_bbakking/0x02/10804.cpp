#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<int> v(20);
    for (int i = 0; i < 20; i++)
    {
        v[i] = i + 1;
    }
    int t = 10;
    int a, b;

    while (t--)
    {
        cin >> a >> b;
        a--;
        b--;
        while (a < b)
        {
            swap(v[a], v[b]);
            a++;
            b--;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}