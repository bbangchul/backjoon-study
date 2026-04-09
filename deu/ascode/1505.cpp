#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    int x, result = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        result ^= x;
    }

    printf("%d\n", result);
}

int main()
{
    solve();
    return 0;
}