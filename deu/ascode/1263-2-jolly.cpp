#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;

    while (cin >> n)
    {
        vector<int> arr(n);
        vector<int> check(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        bool isJolly = true;

        for (int i = 0; i < n - 1; i++)
        {
            int diff = abs(arr[i] - arr[i + 1]);

            if (diff < 1 || diff > n - 1 || check[diff] == 1)
            {
                isJolly = false;
            }
            else
            {
                check[diff] = 1;
            }
        }

        if (isJolly)
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}