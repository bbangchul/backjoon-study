#include <iostream>
using namespace std;

class Car
{
    int speed, gear; // 속도, 기어

public:
    // 생성자
    Car(int s = 0, int g = 0) : speed(s), gear(g)
    {
        cout << "생성자 호출" << endl;
    }

    // 복사 생성자
    Car(const Car &obj) : speed(obj.speed), gear(obj.gear)
    {
        cout << "복사 생성자 호출" << endl;
    }

    void print()
    {
        cout << speed << " " << gear << endl;
    }
};

// 값에 의한 전달 (Call by Value)
Car isMoving(Car obj)
{             // (1) → 복사 생성자 호출
    Car t;    // (2) → 기본 생성자 호출
    t = obj;  // 할당 연산자 (기본 shallow copy)
    return t; // (최적화 없으면 복사 생성자 가능)
}

int main()
{
    Car c(0, 1), d(10, 2), a(c); // (0)

    d = isMoving(c);

    d.print();

    return 0;
}