#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v;
    int m, n;
    int sum = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    while (n--)
    {
        int t, ck = 0;
        cin >> t;
        for (int i = 0; i < m; i++)
        {
            if (t == v[i])
            {
                cout << "true\n";
                ck = 1;
                break;
            }
        }
        if (ck == 0)
        {
            cout << "false\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}