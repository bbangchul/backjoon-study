// [알고리즘 B.13] 구조체와 함수를 이용한 프로그램
#include <iostream>
using namespace std;

typedef struct {
    double x;
    double y;
} Point2D;

double Area(Point2D pt) {
    int area = pt.x * pt.y;
    if (area<0) return -area;
    return area;
}

int main() {
    Point2D pts[10];
    int i;
    double max;

    for (i=0; i<10; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    max = Area(pts[0]);
    for (i=1; i<10; i++) {
        if (max < Area(pts[i])) max = Area(pts[i]);
    }

    cout << max;
}
