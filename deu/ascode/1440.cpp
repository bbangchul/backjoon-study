#include <iostream>
using namespace std;

void solve()
{
    unsigned int a, b;
    int n;
    cin >> a >> b;
    cin >> n;

    unsigned int base = 1;
    for (int i = 0; i < 16 - n; i++)
        base *= 2;

    unsigned int alow = a % base;
    unsigned int blow = b % base;

    unsigned int ahigh = a - alow;
    unsigned int bhigh = b - blow;

    unsigned int new_a = ahigh + blow;
    unsigned int new_b = bhigh + alow;

    cout << new_a << ' ' << new_b << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}