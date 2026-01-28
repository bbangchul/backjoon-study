#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string a, b;
    int arr[26] = {0};
    int brr[26] = {0};
    cin >> a >> b;

    for (char c : a)
        arr[c - 'a']++;
    for (char c : b)
        brr[c - 'a']++;

    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != brr[i])
            arr[i] > brr[i] ? cnt += arr[i] - brr[i] : cnt += brr[i] - arr[i];
    }
    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}