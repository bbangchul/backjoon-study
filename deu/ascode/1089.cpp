#include <iostream>
#include <algorithm>
using namespace std;

int getLength(long long n)
{
    int cnt = 1;

    while (n != 1)
    {
        if (n % 2 == 1)
        {
            n = 3 * n + 1;
        }
        else
        {
            n = n / 2;
        }

        cnt++;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int i, j;
        cin >> i >> j;

        if (i > j)
        {
            swap(i, j);
        }

        int maxM = 0;
        int minM = 100000;

        for (int n = i; n <= j; n++)
        {
            int m = getLength(n);

            if (m > maxM)
            {
                maxM = m;
            }

            if (m < minM)
            {
                minM = m;
            }
        }

        cout << maxM << ' ' << minM << '\n';
    }

    return 0;
}