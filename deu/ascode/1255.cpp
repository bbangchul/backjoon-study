#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a1, a2, a3, a4;
    int b1, b2, b3, b4;

    cin >> a1 >> a2 >> a3 >> a4 >> b1 >> b2 >> b3 >> b4;

    int ax1 = min(a1, a3);
    int ay1 = min(a2, a4);
    int ax2 = max(a1, a3);
    int ay2 = max(a2, a4);

    int bx1 = min(b1, b3);
    int by1 = min(b2, b4);
    int bx2 = max(b1, b3);
    int by2 = max(b2, b4);

    int width = min(ax2, bx2) - max(ax1, bx1);
    int height = min(ay2, by2) - max(ay1, by1);

    if (width <= 0 || height <= 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << width * height << '\n';
    }
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