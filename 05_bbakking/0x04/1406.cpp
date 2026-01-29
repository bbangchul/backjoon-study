#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    list<char> editor(s.begin(), s.end());
    auto cursor = editor.end();

    int M;
    cin >> M;

    while (M--)
    {
        char cmd;
        cin >> cmd;

        switch (cmd)
        {
        case 'L':
            if (cursor != editor.begin())
                cursor--;
            break;

        case 'D':
            if (cursor != editor.end())
                cursor++;
            break;

        case 'B':
            if (cursor != editor.begin())
            {
                cursor--;
                cursor = editor.erase(cursor);
            }
            break;

        case 'P':
        {
            char x;
            cin >> x;
            editor.insert(cursor, x);
            break;
        }
        }
    }

    for (char c : editor)
    {
        cout << c;
    }

    return 0;
}