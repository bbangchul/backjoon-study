#include <iostream>
using namespace std;

void hanoi(int n, char from, char via, char to)
{
    if (n == 1)
    {
        cout << "원판 1을 " << from << " 에서 " << to << "로 옮긴다\n";
        return;
    }

    hanoi(n - 1, from, to, via);
    cout << "원판 " << n << "를 " << from << " 에서 " << to << "로 옮긴다\n";
    hanoi(n - 1, via, from, to);
}

void solve()
{
    int n;
    cin >> n;

    hanoi(n, 'A', 'B', 'C');
    cout << (1 << n) - 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}