#include <iostream>
#include <vector>

using namespace std;

int func2(const vector<int> &arr, int N)
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (arr[i] + arr[j] == 100)
                return 1;
    return 0;
}

int main(void)
{
    vector<int> v;
    int num, f;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> f;
    int r = func2(v, f);
    cout << r;

    return 0;
}