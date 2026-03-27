#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    int arr[3];

    cin >> a >> b >> c;
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    sort(arr, arr + 3);

    int fn;
    fn = arr[0] + arr[1];

    if (arr[0] + arr[1] > arr[2])
    {
        cout << arr[0] + arr[1] + arr[2];
    }
    else
    {
        cout << (arr[0] + arr[1]) * 2 - 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}