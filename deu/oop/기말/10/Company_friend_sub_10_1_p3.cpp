#include <iostream>
using namespace std;

class Company
{
private:
    int sales;
    int profit;

    // friend 함수 선언
    friend void sub(Company &c);

public:
    Company()
    {
        sales = 100;
        profit = 50;
    }
};

// 일반 함수
// Company의 private 멤버 접근 가능
void sub(Company &c)
{
    cout << "sales : " << c.sales << endl;
    cout << "profit : " << c.profit << endl;
}

int main()
{
    Company c1;

    sub(c1);

    return 0;
}