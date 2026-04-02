#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long K = 2432902008176640000LL;
    long long ans = K;

    for (long long i = 1; i <= n; i++)
    {
        ans /= i;
    }

    cout << ans;
}
