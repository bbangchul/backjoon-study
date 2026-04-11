#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a[3][3], r[3] = {0}, c[3] = {0}, ck = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                cin >> a[i][j];
                r[i] += a[i][j];
                c[j] += a[i][j];
            }
        for (int i = 0; i < 3; i++)
            if (r[i] != 15 || c[i] != 15)
                ck = 1;
        if (a[0][0] + a[1][1] + a[2][2] != 15 || a[0][2] + a[1][1] + a[2][0] != 15)
            ck = 1;
        cout << (ck ? "No Magic Square!\n" : "Magic Square!\n");
    }
}