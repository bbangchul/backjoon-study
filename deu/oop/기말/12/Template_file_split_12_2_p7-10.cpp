#include <iostream>
using namespace std;

// 함수 템플릿
template <typename T>
T sum(T a, T b)
{

    return (a + b);
}

int main()
{

    int sum_i;
    double sum_d;

    sum_i = sum(2, 3);

    sum_d = sum(2.2, 3.3);

    cout << "int sum : "
         << sum_i
         << endl;

    cout << "double sum : "
         << sum_d
         << endl;

    return 0;
}