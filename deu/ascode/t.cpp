#include <iostream>
using namespace std;

// 부모 클래스
class Shape
{
    int x, y; // private

public:
    // 기본 생성자
    Shape()
    {
        cout << "Shape 생성자() " << endl;
    }

    // 좌표 초기화 생성자
    Shape(int xloc, int yloc) : x(xloc), y(yloc)
    {
        cout << "Shape 생성자(xloc, yloc) " << endl;
    }

    // 소멸자
    ~Shape()
    {
        cout << "Shape 소멸자() " << endl;
    }
};

// 자식 클래스
class Rectangle : public Shape
{
    int width, height; // private

public:
    // 생성자
    Rectangle(int x = 0, int y = 0, int w = 0, int h = 0);

    // 소멸자
    ~Rectangle()
    {
        cout << "Rectangle 소멸자()" << endl;
    }
};

// 생성자 정의
Rectangle::Rectangle(int x, int y, int w, int h)
    : Shape(x, y) // 부모 생성자 먼저 호출
{
    width = w;
    height = h;

    cout << "Rectangle 생성자(x, y, w, h)" << endl;
}

// main 함수
int main()
{
    Rectangle r(0, 0, 100, 100);

    return 0;
}