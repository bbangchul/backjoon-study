#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal speak()" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "멍멍" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak()
    {
        cout << "야옹" << endl;
    }
};

int main()
{
    Dog d;

    // 참조자
    Animal &a1 = d;

    a1.speak();

    Cat c;

    // 참조자
    Animal &a2 = c;

    a2.speak();

    return 0;
}