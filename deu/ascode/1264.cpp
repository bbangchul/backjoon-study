#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    int cntA[26] = {0};
    int cntB[26] = {0};

    for (int i = 0; i < a.size(); i++) {
        cntA[a[i] - 'a']++;
    }

    for (int i = 0; i < b.size(); i++) {
        cntB[b[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        int c = min(cntA[i], cntB[i]);

        for (int j = 0; j < c; j++) {
            cout << char('a' + i);
        }
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
