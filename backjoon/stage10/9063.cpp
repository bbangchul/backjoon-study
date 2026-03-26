#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;
    int xmin = x, xmax = x, ymin = y, ymax = y;

    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        xmin = min(xmin, x);
        xmax = max(xmax, x);
        ymin = min(ymin, y);
        ymax = max(ymax, y);
    }

    cout << (xmax - xmin) * (ymax - ymin);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}