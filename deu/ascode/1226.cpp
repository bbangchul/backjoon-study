#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x;
    cin >> x;
    string arr[14] = {
        "A++", "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"};

    if (x == 100)
        cout << arr[0];
    else if (x <= 99 && x >= 97)
        cout << arr[1];
    else if (x <= 96 && x >= 93)
        cout << arr[2];
    else if (x <= 92 && x >= 90)
        cout << arr[3];
    else if (x <= 89 && x >= 87)
        cout << arr[4];
    else if (x <= 86 && x >= 83)
        cout << arr[5];
    else if (x <= 82 && x >= 80)
        cout << arr[6];
    else if (x <= 79 && x >= 77)
        cout << arr[7];
    else if (x <= 76 && x >= 73)
        cout << arr[8];
    else if (x <= 72 && x >= 70)
        cout << arr[9];
    else if (x <= 69 && x >= 67)
        cout << arr[10];
    else if (x <= 66 && x >= 63)
        cout << arr[11];
    else if (x <= 62 && x >= 60)
        cout << arr[12];
    else
        cout << arr[13];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}