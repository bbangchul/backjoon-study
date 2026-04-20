#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k;
    cin >> k;

    int arr[5001] = {0};
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + k);

    int tg;
    cin >> tg;

    bool ck = true;

    for (int i = 0; i < k; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int need = tg - arr[i];

        if (binary_search(arr + i + 1, arr + k, need))
        {
            cout << '(' << arr[i] << ", " << need << ") ";
            ck = false;
        }
    }

    if (ck)
    {
        cout << -1;
    }
    cout << '\n';
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