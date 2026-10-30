// [알고리즘 B.12] 배열과 함수를 이용한 프로그램
#include <iostream>
using namespace std;

double Area(double x, double y)
{
    int area = x * y;
    if (area < 0)
        return -area;
    return area;
}

int main()
{
    double x[10], y[10];
    int i;
    double max;

    for (i = 0; i < 10; i++)
        cin >> x[i] >> y[i];

    max = Area(x[0], y[0]);
    for (i = 1; i < 10; i++)
        if (max < Area(x[i], y[i]))
            max = Area(x[i], y[i]);
    cout << max;
}
