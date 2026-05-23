#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 추상 클래스
class Shape
{
protected:
    string color;
    int x, y;

public:
    Shape(string c, int px, int py)
        : color(c), x(px), y(py) {}

    // 공통 기능
    void move(int nx, int ny)
    {
        x = nx;
        y = ny;
    }

    // 순수 가상 함수
    virtual double area() = 0;
    virtual void draw() = 0;

    virtual ~Shape() {}
};

// 사각형
class Rectangle : public Shape
{
private:
    int width, height;

public:
    Rectangle(string c, int px, int py,
              int w, int h)
        : Shape(c, px, py)
    {
        width = w;
        height = h;
    }

    double area()
    {
        return width * height;
    }

    void draw()
    {
        cout << "[Rectangle]" << endl;
        cout << "색상: " << color << endl;
        cout << "위치: (" << x << ", " << y << ")" << endl;
        cout << "가로: " << width << endl;
        cout << "세로: " << height << endl;
        cout << "넓이: " << area() << endl;
    }
};

// 원
class Circle : public Shape
{
private:
    int radius;

public:
    Circle(string c, int px, int py,
           int r)
        : Shape(c, px, py)
    {
        radius = r;
    }

    double area()
    {
        return 3.14 * radius * radius;
    }

    void draw()
    {
        cout << "[Circle]" << endl;
        cout << "색상: " << color << endl;
        cout << "위치: (" << x << ", " << y << ")" << endl;
        cout << "반지름: " << radius << endl;
        cout << "넓이: " << area() << endl;
    }
};

// 삼각형
class Triangle : public Shape
{
private:
    int base, height;

public:
    Triangle(string c, int px, int py,
             int b, int h)
        : Shape(c, px, py)
    {
        base = b;
        height = h;
    }

    double area()
    {
        return base * height / 2.0;
    }

    void draw()
    {
        cout << "[Triangle]" << endl;
        cout << "색상: " << color << endl;
        cout << "위치: (" << x << ", " << y << ")" << endl;
        cout << "밑변: " << base << endl;
        cout << "높이: " << height << endl;
        cout << "넓이: " << area() << endl;
    }
};

int main()
{
    vector<Shape *> shapes;

    shapes.push_back(
        new Rectangle("Red", 0, 0, 10, 5));

    shapes.push_back(
        new Circle("Blue", 3, 4, 7));

    shapes.push_back(
        new Triangle("Green", 5, 2, 8, 6));

    for (int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->draw();

        cout << "------------------" << endl;
    }

    for (int i = 0; i < shapes.size(); i++)
    {
        delete shapes[i];
    }

    return 0;
}