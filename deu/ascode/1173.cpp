#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int h;
        cin >> h;

        for (int i = 0; i < h; i++)
        {
            int word = h - i;
            for (int j = word; j > 0; j--)
            {
                cout << char(65 + i);
            }
            cout << '\n';
        }
        if (t)
            cout << '\n';
    }
}