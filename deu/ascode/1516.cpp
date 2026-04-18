#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    int student_num;
    int time;
} s;

bool cmp(s a, s b)
{
    return a.student_num < b.student_num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    s a[1001];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i].student_num >> a[i].time;

    sort(a, a + n, cmp);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].time >= 10 && a[i].time <= 15)
        {
            cout << a[i].student_num << '\n';
            count++;
        }
    }

    if (count == 0)
        cout << "None";

    return 0;
}