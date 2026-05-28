#include <bits/stdc++.h>
using namespace std;

const int MAX = 3000;
int arr[MAX], iDiff[MAX];

void solve()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < MAX; i++)
        {
            iDiff[i] = 0;
        }

        for (int i = 0; i < n - 1; i++)
        {
            int diff = abs(arr[i] - arr[i + 1]);

            if (diff > 0)
            {
                iDiff[diff] = 1;
            }
        }

        bool isJolly = true;

        for (int i = 1; i <= n - 1; i++)
        {
            if (iDiff[i] == 0)
            {
                isJolly = false;
                break;
            }
        }

        if (isJolly)
        {
            cout << "Jolly\n";
        }
        else
        {
            cout << "Not jolly\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
}