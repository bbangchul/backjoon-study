// [알고리즘 B.10] 기초변수를 이용한 프로그램
#include <iostream>
using namespace std;

int main() {
    double x0, y0;
    double x1, y1;
    double x2, y2;
    double max, area;

    cin >> x0 >> y0;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    max = 0;

    area = x0 * y0;
    if (area<0) area = -area;
    if (max < area) max = area;

    area = x1 * y1;
    if (area<0) area = -area;
    if (max < area) max = area;

    area = x2 * y2;
    if (area<0) area = -area;
    if (max < area) max = area;

    cout << max;
}
