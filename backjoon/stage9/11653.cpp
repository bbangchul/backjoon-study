#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a;

    int idx = 0;
    int i = 2;
    while (n != 1)
    {
        if (n % i == 0)
        {
            a.push_back(i);
            n /= i;
        }
        else
            i++;
    }
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << endl;
    // }

    for (int x : a)
    {
        cout << x << endl;
    }
}
