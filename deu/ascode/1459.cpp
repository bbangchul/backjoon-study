#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> tree(n);

    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end());

    int gapGcd = tree[1] - tree[0];

    for (int i = 2; i < n; i++)
    {
        int gap = tree[i] - tree[i - 1];
        gapGcd = gcd(gapGcd, gap);
    }

    int answer = 0;

    for (int i = 1; i < n; i++)
    {
        int gap = tree[i] - tree[i - 1];
        answer += gap / gapGcd - 1;
    }

    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}