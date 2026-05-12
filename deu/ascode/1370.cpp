#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int mul = 10000;
    int origin = n;
    int reverse = 0;
    while (origin != 0)
    {
        reverse += (origin % 10) * mul;
        origin /= 10;
        mul /= 10;
    }
    if (n == reverse)
    {
        cout << "Palindrome!";
    }
    else
    {
        cout << "No palindrome!";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}