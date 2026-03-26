#include <bits/stdc++.h>
using namespace std;

class CDog
{
public:
    string name;
    string type;

    void Bark()
    {
        cout << "멍멍\n";
    }

    void Show()
    {
        cout << name << '\n';
        cout << type << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    CDog x, y;

    string dogname, dogtype;
    cin >> dogname >> dogtype;
    x.name = dogname;
    x.type = dogtype;
    x.Show();
}