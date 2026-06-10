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
    queue<int> q;
    int n;
    cin >> n;

    while (n--) {
        string in;
        cin >> in;

        if (in == "In") {
            int scv;
            cin >> scv;
            q.push(scv);
        } else if (in == "Out") {
            if (q.empty()) {
                cout << "Empty\n";
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
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
