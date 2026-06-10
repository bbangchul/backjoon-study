#include <iostream>
#include <stdexcept>
using namespace std;

class Resource
{
private:
    int id_;

public:
    Resource(int id)
    {
        id_ = id;
    }

    ~Resource()
    {
        cout << "리소스 해제 : " << id_ << endl;
    }
};

int func3()
{
    Resource r3(3);

    throw runtime_error("Exception from 3!");

    cout << "실행 안됨!" << endl;
    return 0;
}

int func2()
{
    Resource r2(2);

    func3();

    cout << "실행 안됨!" << endl;
    return 0;
}

int func1()
{
    Resource r1(1);

    func2();

    cout << "실행 안됨!" << endl;
    return 0;
}

int main()
{
    try
    {
        func1();
    }
    catch (exception &e)
    {
        cout << "Exception : " << e.what() << endl;
    }

    return 0;
}