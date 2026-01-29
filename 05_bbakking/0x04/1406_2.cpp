#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num)
{
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
}
void traversal()
{
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << (char)dat[cur];
        cur = nxt[cur];
    }
}
void solve()
{
    string s;
    cin >> s;
    int cursor = 0;
    for (auto c : s)
    {
        insert(cursor, c);
        cursor = nxt[cursor];
    }

    int m;
    cin >> m;

    while (m--)
    {
        char cmd;
        cin >> cmd;
        if (cmd == 'P')
        {
            char add;
            cin >> add;
            insert(cursor, add);
            cursor = nxt[cursor];
        }
        else if (cmd == 'L')
        {
            if (pre[cursor] != -1)
                cursor = pre[cursor];
        }
        else if (cmd == 'D')
        {
            if (nxt[cursor] != -1)
                cursor = nxt[cursor];
        }
        else
        {
            if (cursor != 0)
            {
                erase(cursor);
                cursor = pre[cursor];
            }
        }
    }

    traversal();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    solve();
}