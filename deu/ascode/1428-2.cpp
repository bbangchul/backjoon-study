#include <bits/stdc++.h>
using namespace std;

int find(int n, int A[], int target)
{
    int min = 0;
    int max = n - 1;
    int mid;
    while (1)
    {
        mid = (min + max) / 2;
        if (A[mid] == target)
            return 1;
        else if (target > A[mid])
            min = mid + 1;
        else
            max = mid - 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    int arr[100001] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        int findresult = find(n, arr, t);
        if (findresult)
            cout << "true\n";
        else
            cout << "false\n";
    }
}
