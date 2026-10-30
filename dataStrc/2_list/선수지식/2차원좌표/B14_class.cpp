// [알고리즘 B.14] 클래스를 이용한 프로그램
#include <iostream>
using namespace std;

class Point2D {
public:
    int Area() {
        int area = x * y;
        if (area<0) return -area;
        return area;
    }
// private:
    double x;
    double y;
};

int main() {
    Point2D pts[10];
    int i;
    double max;

    for (i=0; i<10; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    max = pts[0].Area();
    for (i=1; i<10; i++) {
        if (max < pts[i].Area()) max = pts[i].Area();
    }

    cout << max;
}
