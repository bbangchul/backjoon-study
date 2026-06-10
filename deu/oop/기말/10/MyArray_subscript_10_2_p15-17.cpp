#include <iostream>
#include <cassert>
using namespace std;

class MyArray
{
private:
    int *data;
    int size;

public:
    // 생성자
    MyArray(int s = 10)
    {
        size = s;

        data = new int[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }

    // 소멸자
    ~MyArray()
    {
        delete[] data;
    }

    // 배열 크기 반환
    int getSize() const
    {
        return size;
    }

    // [] 연산자 중복
    int &operator[](int index)
    {

        // 범위 체크
        assert(index >= 0 && index < size);

        return data[index];
    }

    // << 연산자 중복
    friend ostream &operator<<(ostream &os,
                               const MyArray &a);
};

// <<
ostream &operator<<(ostream &os,
                    const MyArray &a)
{

    for (int i = 0; i < a.size; i++)
    {
        os << a.data[i] << " ";
    }

    return os;
}

int main()
{

    MyArray a1(10);

    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 3;
    a1[3] = 4;

    cout << a1 << endl;

    return 0;
}