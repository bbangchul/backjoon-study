#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000;

bool prime[MAX + 1];

int reverseNum(int n)
{
    int rev = 0;

    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    return rev;
}

void makePrime()
{
    for (int i = 2; i <= MAX; i++)
    {
        prime[i] = true;
    }

    for (int i = 2; i * i <= MAX; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

void solve()
{
    makePrime();

    vector<int> emirp;

    for (int i = 1; i <= MAX; i++)
    {
        int rev = reverseNum(i);

        if (i != rev && prime[i] && prime[rev])
        {
            emirp.push_back(i);
        }
    }

    int m, n;
    cin >> m >> n;

    if (m > n)
    {
        swap(m, n);
    }

    int minVal = 0;
    int maxVal = 0;
    int cnt = 0;

    for (int x : emirp)
    {
        if (x >= m && x <= n)
        {
            if (cnt == 0)
            {
                minVal = x;
            }

            maxVal = x;
            cnt++;
        }
    }

    if (cnt == 0)
    {
        cout << "0 0 0\n";
    }
    else
    {
        cout << maxVal << ' ' << minVal << ' ' << cnt << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}