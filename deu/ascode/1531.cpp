#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r)
{
    if (r < 0 || r > n)
    {
        return 0;
    }
    if (r == 0 || r == n)
    {
        return 1;
    }
    if (r > n / 2)
    {
        r = n - r;
    }
    long long res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (n - i + 1) / i;
    }
    return res;
}

long long catalan(int n)
{
    return nCr(2 * n, n) / (n + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << catalan(n);
}