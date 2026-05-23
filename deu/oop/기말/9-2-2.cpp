#include <iostream>
using namespace std;

// 추상 클래스
class Animal
{
public:
    virtual void move() = 0;
    virtual void eat() = 0;
    virtual void speak() = 0;
};

class Lion : public Animal
{
public:
    void move()
    {
        cout << "사자의 move()" << endl;
    }

    void eat()
    {
        cout << "사자의 eat()" << endl;
    }

    void speak()
    {
        cout << "사자의 speak()" << endl;
    }
};

class GoldFish : public Animal
{
public:
    void move()
    {
        cout << "GoldFish의 move()" << endl;
    }

    void eat()
    {
        cout << "GoldFish의 eat()" << endl;
    }

    void speak()
    {
        cout << "GoldFish의 speak()" << endl;
    }
};

class Eagle : public Animal
{
public:
    void move()
    {
        cout << "Eagle의 move()" << endl;
    }

    void eat()
    {
        cout << "Eagle의 eat()" << endl;
    }

    void speak()
    {
        cout << "Eagle의 speak()" << endl;
    }
};

int main()
{
    Animal *a1 = new Lion();
    Animal *a2 = new GoldFish();
    Animal *a3 = new Eagle();

    a1->move();
    a1->eat();
    a1->speak();

    cout << endl;

    a2->move();
    a2->eat();
    a2->speak();

    cout << endl;

    a3->move();
    a3->eat();
    a3->speak();

    delete a1;
    delete a2;
    delete a3;

    return 0;
}