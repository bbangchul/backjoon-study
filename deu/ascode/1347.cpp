#include <bits/stdc++.h>
using namespace std;

void solve() {
    int maxValue = -1;

    int maxRow = 0;

    int maxCol = 0;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int num;
            cin >> num;
            if (num >= maxValue) {
                maxValue = num;
                maxRow = i;
                maxCol = j;
            }
        }
    }

    cout << maxValue << '\n';

    cout << maxRow << ' ' << maxCol << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
