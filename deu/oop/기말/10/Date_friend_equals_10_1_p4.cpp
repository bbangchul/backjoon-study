#include <iostream>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;

    // friend 함수 선언
    friend bool equals(Date d1, Date d2);

public:
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
};

// 일반 함수
// Date의 private 멤버 접근 가능
bool equals(Date d1, Date d2)
{
    return (d1.year == d2.year) &&
           (d1.month == d2.month) &&
           (d1.day == d2.day);
}

int main()
{
    Date d1(2025, 5, 28);
    Date d2(2025, 5, 28);

    if (equals(d1, d2))
        cout << "같은 날짜" << endl;
    else
        cout << "다른 날짜" << endl;

    return 0;
}