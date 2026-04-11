#include <iostream>

using namespace std;

class Box
{
private:
    int w, h, v_h;

public:
    Box()
    {
        w = 1;
        h = 1;
        v_h = 1;
    }

    Box(int width, int height, int vh)
    {
        w = width;
        h = height;
        v_h = vh;
    }

    int getVolume();
    void print();
    ~Box() {};
};

int Box::getVolume()
{
    return w * h * v_h;
}
void Box::print()
{
    cout << "밑면적 : " << w * h << "    상자 높이 : " << v_h << "    부피 : " << getVolume() << '\n';
}

int main()
{
    Box b1(2, 3, 4), b2(4, 5, 6);
    Box b3;

    cout << "=======================6_1=================\n";
    cout << "박스 1 ";
    b1.print();
    cout << "박스 2 ";
    b2.print();
    cout << "박스 3 ";
    b3.print();
    cout << "========================================\n";

    int vb1 = b1.getVolume();
    int vb2 = b2.getVolume();
    int vb3 = b3.getVolume();

    int maxVolume = vb1;
    int max = 1;

    if (vb2 > maxVolume)
    {
        maxVolume = vb2;
        max = 2;
    }

    if (vb3 > maxVolume)
    {
        maxVolume = vb3;
        max = 3;
    }

    cout << "박스" << max << "의 부피가 가장 큽니다 : " << maxVolume << "\n\n";

    return 0;
}