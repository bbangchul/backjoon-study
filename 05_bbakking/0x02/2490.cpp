#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 3;
    while (t--)
    {
        vector<int> v(4);
        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> v[i];
            if (v[i] == 0)
            {
                cnt++;
            }
        }
        if (cnt == 0)
            cout << "E\n";
        else if (cnt == 1)
            cout << "A\n";
        else if (cnt == 2)
            cout << "B\n";
        else if (cnt == 3)
            cout << "C\n";
        else
            cout << "D\n";
    }
}