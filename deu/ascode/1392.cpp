#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct
{
    string name;
    int y, m, d;
} s;

bool cmp(s a, s b)
{
    if (a.y != b.y)
        return a.y < b.y;
    if (a.m != b.m)
        return a.m < b.m;
    if (a.d != b.d)
        return a.d < b.d;
    return a.name < b.name;
}

void solve()
{
    vector<s> v;
    s s;

    while (cin >> s.name >> s.y >> s.m >> s.d)
    {
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);

    int lv = v.size();

    for (int i = 0; i < lv; i++)
    {
        cout << v[i].name << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}