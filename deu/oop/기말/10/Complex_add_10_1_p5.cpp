#include <iostream>
using namespace std;

class Complex
{
private:
    double re; // 실수부
    double im; // 허수부

public:
    // friend 함수 선언
    friend Complex add(Complex a1, Complex a2);

    Complex(double r, double i)
    {
        re = r;
        im = i;
    }

    Complex()
    {
        re = 0;
        im = 0;
    }

    void Output()
    {
        cout << re << " + " << im << "i" << endl;
    }
};

// 일반 함수
Complex add(Complex a1, Complex a2)
{
    return Complex(a1.re + a2.re,
                   a1.im + a2.im);
}

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);

    Complex c3 = add(c1, c2);

    c3.Output();

    return 0;
}