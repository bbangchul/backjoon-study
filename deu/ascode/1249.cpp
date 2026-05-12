#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int mul = 1000;
    int origin = n;
    int reverse = 0;
    while (origin != 0)
    {
        reverse += (origin % 10) * mul;
        origin /= 10;
        mul /= 10;
    }
    if (n > reverse)
    {
        cout << n << '\n';
    }
    else
    {
        cout << reverse << '\n';
    }
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