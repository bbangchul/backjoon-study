#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m;
    cin >> m;
    int maxVal = 0;
    int minVal = 1001;

    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        maxVal = max(maxVal, n);
        minVal = min(minVal, n);
    }

    int diff = maxVal - minVal;

    if (diff != 0 && maxVal % diff == 0 && minVal % diff == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
