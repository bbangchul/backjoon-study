#include <cmath>
#include <iostream>

using namespace std;

double x, x2, y, y2;
double a, b, c;

double dist_2d(double tx, double tx2, double ty, double ty2)
{
    double t, t2;
    t = pow((tx2 - tx), 2);
    t2 = pow((ty2 - ty), 2);
    return sqrt(t + t2);
}

void quad_eqn(double a, double b, double c)
{
    double t, d, q;
    t = b * b - 4 * a * c;
    if (t < 0)
    {
        cout << "근이 없습니다.";
    }
    else
    {
        d = (-b + sqrt(t)) / (2 * a);
        q = (-b - sqrt(t)) / (2 * a);
        cout << d << '\n'
             << q;
    }
}

void P9()
{
    double r;
    cin >> x >> x2 >> y >> y2;
    r = dist_2d(x, x2, y, y2);
    cout << r << '\n';
}

void P10()
{
    cin >> a >> b >> c;
    quad_eqn(a, b, c);
}

int main()
{
    P9();
    P10();
}
