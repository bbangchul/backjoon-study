#include <bits/stdc++.h>
using namespace std;

long long factorialRecursive(int n)
{
    if (n <= 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num = 10;
    std::cout << num << "! = " << factorialRecursive(num) << std::endl;
    return 0;
}