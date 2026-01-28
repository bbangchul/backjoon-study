#include <iostream>
using namespace std;
int func1(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    return sum;
}

int main(void)
{
    int a;
    cin >> a;
    cout << func1(a);
}