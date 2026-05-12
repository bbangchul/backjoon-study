#include <bits/stdc++.h>
using namespace std;

class Shape
{
protected:
    int x, y;

public:
    virtual void draw()
    {
        cout << "Shape Draw" << endl;
    }
};

class Circle : public Shape
{
private:
    int radius;

public:
    void draw()
    {
        cout << "Circle Draw" << endl;
    }
};

class Rectangle : public Shape
{
private:
    int width, height;

public:
    void draw()
    {
        cout << "Rectangle Draw" << endl;
    }
};

class Triangle : public Shape
{
private:
    int base, height;

public:
    void draw()
    {
        cout << "Triangle Draw" << endl;
    }
};

class Parallelogram : public Shape // 평행사변형 추가
{
public:
    void draw()
    {
        cout << "Parallelogram Draw" << endl;
    }
};

int main()
{
    Shape *arrayOfShapes[4];

    arrayOfShapes[0] = new Rectangle();
    arrayOfShapes[1] = new Triangle();
    arrayOfShapes[2] = new Circle();
    arrayOfShapes[3] = new Parallelogram();
    for (int i = 0; i < 4; i++)
    {
        arrayOfShapes[i]->draw();
    }

    for (int i = 0; i < 4; i++)
    {
        delete arrayOfShapes[i];
    }

    return 0;
}