// 터미널 입력 예시
// 12.0 + 17.9i
// 6.0 + 6.9i
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Dice
{
private:
    int face;

public:
    Dice();
    void roll();
    int getResult();
};

Dice::Dice()
{
    face = 1;
}

void Dice::roll()
{
    face = (int)(rand() % 6 + 1);
}

int Dice::getResult()
{
    return face;
}

void p3()
{
    cout << "=======p3==========\n\n";

    Dice d;

    for (int i = 0; i < 10; i++)
    {
        d.roll();
        cout << "Roll " << i + 1 << " : " << d.getResult() << "\n";
    }

    cout << "\n=======p3==========\n\n";
}

class Complex
{
private:
    double fr, rear;

public:
    Complex();
    void input();
    void print();
    Complex add(const Complex &other);
    Complex sub(const Complex &other);
};

Complex::Complex()
{
    fr = 0;
    rear = 0;
}

void Complex::input()
{
    char plus, i_sign;
    cin >> fr >> plus >> rear >> i_sign;
}

void Complex::print()
{
    cout << fr << " + " << rear << "i";
}

Complex Complex::add(const Complex &other)
{
    Complex result;
    result.fr = this->fr + other.fr;
    result.rear = this->rear + other.rear;
    return result;
}

Complex Complex::sub(const Complex &other)
{
    Complex result;
    result.fr = this->fr - other.fr;
    result.rear = this->rear - other.rear;
    return result;
}

void p6()
{
    Complex c1, c2;

    c1.input();
    c2.input();

    // c1.print();
    // cout << '\n';
    // c2.print();
    // cout << '\n';

    Complex sum = c1.add(c2);
    cout << "덧셈 : ";
    sum.print();
    cout << '\n';

    Complex diff = c1.sub(c2);
    cout << "뺄셈 : ";
    diff.print();
}

int main()
{
    srand(time(0));

    p3();
    p6();

    return 0;
}