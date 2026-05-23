#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 추상 클래스
class RemoteControl
{
public:
    virtual void turnON() = 0;
    virtual void turnOFF() = 0;

    virtual ~RemoteControl() {}
};

class Television : public RemoteControl
{
public:
    void turnON()
    {
        cout << "TV 전원을 켭니다." << endl;
    }

    void turnOFF()
    {
        cout << "TV 전원을 끕니다." << endl;
    }
};

class Refrigerator : public RemoteControl
{
public:
    void turnON()
    {
        cout << "냉장고 전원을 켭니다." << endl;
    }

    void turnOFF()
    {
        cout << "냉장고 전원을 끕니다." << endl;
    }
};

int main()
{
    RemoteControl *pt = new Television();

    pt->turnON();
    pt->turnOFF();

    cout << endl;

    RemoteControl *pr = new Refrigerator();

    pr->turnON();
    pr->turnOFF();

    delete pt;
    delete pr;

    return 0;
}