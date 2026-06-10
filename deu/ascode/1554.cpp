#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    int a[101] = {0};
    int b[101] = {0};

    while (cin >> n) {
        if (n == 0) {
            break;
        }
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i] == b[j]) {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
