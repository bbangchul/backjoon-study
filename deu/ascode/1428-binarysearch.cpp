#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    int arr[100001] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;

        if (binary_search(arr, arr + n, t))
            cout << "true\n";
        else
            cout << "false\n";
    }
}
