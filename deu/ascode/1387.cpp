#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int arr[3][3] = {0};
    int ans[3] = {0};
    int row[3] = {0};
    int ck = 0;
    bool used[10] = {false};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] < 1 || arr[i][j] > 9 || used[arr[i][j]])
            {
                ck = 1;
            }
            else
            {
                used[arr[i][j]] = true;
            }
            ans[i] += arr[i][j];
            row[j] += arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (ans[i] != 15 || row[i] != 15)
        {
            ck = 1;
        }
    }

    if (arr[0][0] + arr[1][1] + arr[2][2] != 15)
    {
        ck = 1;
    }
    if (arr[0][2] + arr[1][1] + arr[2][0] != 15)
    {
        ck = 1;
    }

    if (ck)
    {
        cout << "No Magic Square!\n";
    }
    else
    {
        cout << "Magic Square!\n";
    }
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