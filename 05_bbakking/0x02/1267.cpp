#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<int> v(21);
    int n;
    cin >> n;
    int y = 0, ym = 0;
    int m = 0, mm = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        y = v[i];
        m = v[i];
        while (y >= 0)
        {
            y -= 30;
            ym += 10;
        }
        while (m >= 0)
        {
            m -= 60;
            mm += 15;
        }
    }

    if (ym > mm)
    {
        cout << "M " << mm;
    }
    else if (ym < mm)
    {
        cout << "Y " << ym;
    }
    else
    {
        cout << "Y M " << mm;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}