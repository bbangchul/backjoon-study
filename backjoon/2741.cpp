#include <bits/stdc++.h>
using namespace std;

class Cppstack

{
public:
    Cppstack();
    void solve(int a);
    ~Cppstack();
};

Cppstack::Cppstack()
{
}
Cppstack::~Cppstack()
{
}

void Cppstack::solve(int a)
{
    for (int i = 0; i < a; i++)
    {
        cout << i + 1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Cppstack a;
    a.solve(n);
}