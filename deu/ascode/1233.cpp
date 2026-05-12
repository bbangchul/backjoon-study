#include <bits/stdc++.h>
using namespace std;

int isPrime(unsigned int x)
{
    unsigned limit, i;
    if (x == 2)
        return 1;
    if (x <= 1 || x % 2 == 0)
        return 0;
    limit = (int)sqrt((double)x);
    for (i = 3; i <= limit; i += 2)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    int ck = isPrime(n);
    if (ck)
    {
        cout << "Prime\n";
    }
    else
    {
        cout << "Not Prime\n";
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