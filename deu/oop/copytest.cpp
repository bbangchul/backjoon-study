#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    char *name; // 이름
    int number;

public:
    // 생성자
    Student(const char *p, int n)
    {
        cout << "메모리 할당" << endl;
        name = new char[strlen(p) + 1];
        strcpy(name, p);
        number = n;
    }

    // 복사 생성자
    Student(const Student &s)
    {
        cout << "메모리 할당" << endl;
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        number = s.number;
    }

    // 소멸자
    ~Student()
    {
        cout << "메모리 소멸" << endl;
        delete[] name;
    }

    void show() const
    {
        cout << "name: " << name << ", number: " << number << endl;
    }
};

int main()
{
    Student s1("Park", 2);
    Student s2(s1); // 복사 생성자 호출

    s1.show();
    s2.show();

    return 0;
}