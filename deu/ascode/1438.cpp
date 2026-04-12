#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int r = 7;
    for (int i = 1; i < n; i++)
    {
        r += 4;
    }
    cout << r;
}