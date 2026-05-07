#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve()
{

    int a, b;
    cin >> a >> b;

    bool ck = true;
    int g = gcd(a, b);

    b /= g;

    for (int i = 2; i * i <= b; i++)
    {
        while (b % i == 0)
        {
            if (i != 2 && i != 5)
            {
                ck = false;
            }
            b /= i;
        }
    }

    if (b > 1 && b != 2 && b != 5)
    {
        ck = false;
    }

    if (ck)
    {
        cout << "Limited\n";
    }

    else
    {
        cout << "Unlimited\n";
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