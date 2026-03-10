#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &vec, int tg)
{
    int left = 0;
    int right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid] == tg)
        {
            return mid;
        }
        else if (vec[mid] < tg)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void solve()
{
    vector<int> v;
    int m, n;
    int sum = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    while (n--)
    {
        int t;
        cin >> t;
        int r = search(v, t);
        if (r && r != -1)
            sum++;
    }

    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}