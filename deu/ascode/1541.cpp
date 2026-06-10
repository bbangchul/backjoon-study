#include <bits/stdc++.h>
using namespace std;

void solve() {

    long long A, B, V;
    cin >> A >> B >> V;

    long long days = (V - B - 1) / (A - B) + 1;

    cout << days << '\n';
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
