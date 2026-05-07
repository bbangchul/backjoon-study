#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
    }

    int getX() { return x; }
    int getY() { return y; }
};

class Shape
{
protected:
    Point start, end;

public:
    Shape(int x1, int y1, int x2, int y2)
        : start(x1, y1), end(x2, y2) {}
};

class Line : public Shape
{
public:
    Line(int x1, int y1, int x2, int y2)
        : Shape(x1, y1, x2, y2) {}

    void Draw()
    {
        cout << "시작점 : (" << start.getX() << ", " << start.getY() << ") ";
        cout << "끝점 : (" << end.getX() << ", " << end.getY() << ")" << endl;
        cout << "직선 그린다." << endl;
    }
};

class Circle : public Shape
{
public:
    Circle(int x1, int y1, int x2, int y2)
        : Shape(x1, y1, x2, y2) {}

    void Draw()
    {
        cout << "시작점 : (" << start.getX() << ", " << start.getY() << ") ";
        cout << "끝점 : (" << end.getX() << ", " << end.getY() << ")" << endl;
        cout << "원 그린다." << endl;
    }
};

void p8_2()
{
    Circle a(1, 1, 5, 5);
    Line b(5, 5, 9, 9);

    a.Draw();
    b.Draw();
}

int main()
{
    p8_2();
    return 0;
}