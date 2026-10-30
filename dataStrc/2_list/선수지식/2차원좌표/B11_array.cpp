// [알고리즘 B.11] 배열을 이용한 프로그램
#include <iostream>
using namespace std;

int main() {
    double x[10], y[10];
    int i;
    double max, area;

    for (i=0; i<10; i++) {
        cin >> x[i] >> y[i];
    }

    max = 0;
    for (i=0; i<10; i++) {
        area = x[i] * y[i];
        if (area<0) area = -area;
        if (max < area) max = area;
    }

    cout << max;
}
