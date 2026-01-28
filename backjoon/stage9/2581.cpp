#include <iostream>

using namespace std;

bool primary(int a)
{
    if (a <= 1)
        return false;
    if (a == 2)
        return true;
    if (a % 2 == 0)
        return false;
    for (int i = 3; i * i <= a; i += 2)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int m, n;
    cin >> m >> n;

    int sum = 0;
    int min = 0;

    for (int i = m; i <= n; i++)
    {
        if (primary(i))
        {
            sum += i;
            if (min == 0)
                min = i;
        }
    }

    if (min == 0)
    {
        cout << "-1";
    }
    else
    {
        cout << sum << "\n"
             << min;
    }
}