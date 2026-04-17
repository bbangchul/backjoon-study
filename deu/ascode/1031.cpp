#include <cstdio>
#include <iostream>

void solve()
{
    unsigned long long N;
    scanf("%llu", &N);

    unsigned long long x = 1;
    int a = 0;

    while (x < N)
    {
        x *= 2;
        a++;
    }

    printf("%d\n", a);
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        solve();
    }

    return 0;
}