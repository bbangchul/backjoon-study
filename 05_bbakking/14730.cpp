#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0;
    cin >> n;
    while (n--)
    {
        int c, k;
        cin >> c >> k;
        sum += c * k;
    }
    cout << sum;
    return 0;
}