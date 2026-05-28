#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak() const
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
    Animal &a1 = d;

    a1.speak();

    Cat c;
    Animal &a2 = c;

    a2.speak();

    return 0;
}