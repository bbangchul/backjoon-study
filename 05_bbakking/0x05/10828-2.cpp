#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

class Cppstack
{
public:
    Cppstack() {};
    int push(int x);
    int pop();
    int size();
    int empty();
    int top();
    ~Cppstack() {};
};

int Cppstack::push(int x)
{
    vec.push_back(x);
    return 0;
}

int Cppstack::pop()
{
    if (vec.empty())
        return -1;
    int val = vec.back();
    vec.pop_back();
    return val;
}

int Cppstack::size()
{
    return vec.size();
}

int Cppstack::empty()
{
    return vec.empty() ? 1 : 0;
}

int Cppstack::top()
{
    if (vec.empty())
        return -1;
    return vec.back();
}

void solve()
{
    int n;
    cin >> n;
    Cppstack sk;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int X;
            cin >> X;
            sk.push(X);
        }
        else if (s == "pop")
        {
            cout << sk.pop() << '\n';
        }
        else if (s == "size")
        {
            cout << sk.size() << '\n';
        }
        else if (s == "empty")
        {
            cout << sk.empty() << '\n';
        }
        else if (s == "top")
        {
            cout << sk.top() << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}