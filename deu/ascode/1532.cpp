#include <bits/stdc++.h>
using namespace std;

long long fact(int n)
{
    long long r = 1;
    for (int i = 1; i <= n; i++)
        r *= i;
    return r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long long numerator = fact(2 * n) / fact(n);
        long long denominator = fact(n + 1);
        long long result = numerator / denominator;

        cout << numerator << " / " << denominator << " = " << result << '\n';
    }
}