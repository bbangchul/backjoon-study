#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solve() {
    queue<int> q1;
    queue<int> q2;

    int n;
    cin >> n;

    long long q1sum = 0, q2sum = 0;

    for (int i = 0; i < n; i++) {
        int tem;
        cin >> tem;
        q1sum += tem;
        q1.push(tem);
    }

    for (int i = 0; i < n; i++) {
        int tem;
        cin >> tem;
        q2sum += tem;
        q2.push(tem);
    }

    int cnt = 0;
    int limit = 4 * n;

    while (cnt <= limit) {
        if (q1sum == q2sum) {
            cout << cnt << '\n';
            return;
        }
        if (q1sum > q2sum) {
            int tem = q1.front();
            q1.pop();
            q2.push(tem);
            q1sum -= tem;
            q2sum += tem;
        } else {
            int tem = q2.front();
            q2.pop();
            q1.push(tem);
            q2sum -= tem;
            q1sum += tem;
        }
        cnt++;
    }

    cout << -1 << '\n';
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
