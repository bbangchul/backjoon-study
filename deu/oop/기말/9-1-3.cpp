#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    int salary;
    int full_time;

public:
    Employee(string n, int s, int f)
        : name(n), salary(s), full_time(f) {}

    string getName() const
    {
        return name;
    }

    int getSalary() const
    {
        return salary;
    }

    bool getFullTime() const
    {
        return full_time;
    }

    // 공통 속성 출력
    virtual void display() const
    {
        cout << "이름: " << name << endl;
        cout << "월급: " << salary << endl;

        if (full_time)
            cout << "정규직" << endl;
        else
            cout << "비정규직" << endl;
    }
};

class FullTime : public Employee
{
private:
    int bonus;

public:
    FullTime(string n, int f, int s, int b)
        : Employee(n, s, f)
    {
        bonus = b;
    }

    void display() const
    {
        Employee::display(); // 부모 출력

        // 자신의 것만 출력
        cout << "보너스: " << bonus << endl;
    }
};

class PartTime : public Employee
{
private:
    string EndDate;

public:
    PartTime(string n, int f, int s, string e)
        : Employee(n, s, f)
    {
        EndDate = e;
    }

    void display() const
    {
        Employee::display(); // 부모 출력

        // 자신의 것만 출력
        cout << "계약 종료일: " << EndDate << endl;
    }
};

int main()
{
    Employee *a =
        new FullTime("김철수", 1, 200, 120);

    Employee *b =
        new PartTime("김현빈", 0, 150, "181230");

    // Full time 호출
    a->display();

    cout << endl;

    b->display();

    delete a;
    delete b;

    return 0;
}