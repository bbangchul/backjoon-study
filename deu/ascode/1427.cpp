#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50;
int n, m, k[MAX_N];
int kk[MAX_N * MAX_N];

bool BinSearch2(int x)
{
    int left = 0, right = n * n;
    while (right - left >= 1)
    {
        int mid = (left + right) / 2;
        if (kk[mid] == x)
            return true;
        else if (kk[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return false;
}

bool Found()
{
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            if (BinSearch2(m - k[a] - k[b]))
            {
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    bool f;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }

    for (int c = 0; c < n; c++)
    {
        for (int d = 0; d < n; d++)
        {
            kk[c * n + d] = k[c] + k[d];
        }
    }
    sort(kk, kk + n * n);
    f = Found();
    if (f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
