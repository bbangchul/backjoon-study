#include <iostream>
using namespace std;

int func4(int n)
{
    int val = 1;
    while (2 * val <= n)
    {
        val *= 2;
    }
    return val;
}

int main(void)
{
    int a;
    cin >> a;
    cout << func4(a);
}