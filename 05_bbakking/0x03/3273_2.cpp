#include <bits/stdc++.h>
using namespace std;

int a[2000001] = {};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t, x, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        a[t]++;
    }

    cin >> x;
    for (int i = 1; i < (x + 1) / 2; ++i)
    {
        // 합이 x가 되는 서로 다른 자연수 (i,x-i)가 존재할 경우
        if (a[i] == 1 && a[x - i] == 1)
            ans++;
    }
    cout << ans;
}
