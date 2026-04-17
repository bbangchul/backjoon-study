#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[3];

    int ck = 0;
    while (n--)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        if (arr[0] + arr[1] + arr[2] > 1)
        {
            ck++;
        }
    }

    cout << ck;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}