#include <iostream>
using namespace std;

class Negate
{

public:
    // 함수 호출 연산자 중복
    int operator()(int value)
    {

        return -value;
    }
};

int main()
{

    Negate neg;

    cout << neg(100) << endl;

    return 0;
}