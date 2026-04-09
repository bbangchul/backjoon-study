#include <iostream>

using namespace std;

long long fibonacci(int n)
{
    if (n <= 1)
        return n;

    long long prev = 0; // 0번째 항
    long long curr = 1; // 1번째 항
    long long next;

    for (int i = 2; i <= n; i++)
    {
        next = prev + curr;
        prev = curr;
        curr = next;
        cout << next << ' ' << prev << ' ' << curr << '\n';
    }
    return curr;
}

int main()
{
    int n = 10;
    std::cout << n << "번째 피보나치 수: " << fibonacci(n) << std::endl;
    return 0;
}
