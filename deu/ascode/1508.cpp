#include <iostream>
using namespace std;

void solve()
{
    long long n;
    cin >> n;

    long long x = n;
    long long rev = 0;

    while (x > 0)
    {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }

    if (n == rev)
    {
        cout << "Same!\n";
    }
    else
    {
        if (n > rev)
            cout << n - rev << '\n';
        else
            cout << rev - n << '\n';
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