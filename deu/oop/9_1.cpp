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

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }
};

class Shape
{
private:
    Point start, end;

protected:
    Shape(int x1, int y1, int x2, int y2)
        : start(x1, y1), end(x2, y2) {}

    void printPoint()
    {
        cout << "좌상단점 : ("
             << start.getX() << ", "
             << start.getY() << ")" << endl;

        cout << "우하단점 : ("
             << end.getX() << ", "
             << end.getY() << ")" << endl;
    }

public:
    virtual void Draw()
    {
        printPoint();
    }

    virtual ~Shape() {}
};

class Line : public Shape
{
public:
    Line(int x1, int y1, int x2, int y2)
        : Shape(x1, y1, x2, y2) {}

    void Draw() override
    {
        Shape::Draw();
        cout << "직선 그린다." << endl;
    }
};

class Circle : public Shape
{
public:
    Circle(int x1, int y1, int x2, int y2)
        : Shape(x1, y1, x2, y2) {}

    void Draw() override
    {
        Shape::Draw();
        cout << "원 그린다." << endl;
    }
};

int main()
{
    Circle a(1, 1, 5, 5);
    Line b(5, 5, 9, 9);

    a.Draw();
    b.Draw();

    Shape *p;

    p = new Line(10, 10, 100, 100);
    p->Draw();

    delete p;

    p = new Circle(100, 100, 200, 200);
    p->Draw();

    delete p;

    return 0;
}