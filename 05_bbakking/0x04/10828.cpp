#include <bits/stdc++.h>

using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x)
{
    dat[pos] = x;
    pos++;
}

void pop()
{
    if (dat[pos - 1] != 0)
    {
        cout << dat[pos - 1] << '\n';
        pos--;
    }
    else
    {
        cout << "-1\n";
    }
}

void top()
{
    if (dat[pos - 1] != 0)
    {
        cout << dat[pos - 1] << '\n';
    }
    else
    {
        cout << "-1\n";
    }
}

void size()
{
    cout << pos << '\n';
}

void empty()
{
    if (dat[pos - 1] != 0)
    {
        cout << "0\n";
    }
    else
    {
        cout << "1\n";
    }
}

void solve()
{
    int n;
    cin >> n;
    while (n--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (cmd == "pop")
        {
            pop();
        }
        else if (cmd == "size")
            size();
        else if (cmd == "empty")
            empty();
        else
            top();
    }
}

int main(void)
{
    solve();
}