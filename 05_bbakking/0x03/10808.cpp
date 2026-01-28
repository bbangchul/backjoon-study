#include <bits/stdc++.h>
using namespace std;

int a[26];
void solve()
{
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (auto c : s)
        a[c - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        cout << a[i] << ' ';
    }
}