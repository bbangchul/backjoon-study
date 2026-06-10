#include <iostream>
using namespace std;

template <typename T>
class Box
{

private:
    T data;

public:
    Box() {}

    void set(T value);

    T get();
};

// 클래스 외부 정의
template <typename T>
void Box<T>::set(T value)
{

    data = value;
}

template <typename T>
T Box<T>::get()
{

    return data;
}

int main()
{

    Box<int> box;

    box.set(100);

    cout << box.get() << endl;

    Box<double> box1;

    box1.set(3.141592);

    cout << box1.get() << endl;

    return 0;
}