#include <iostream>

using namespace std;

class Array
{
    int *data;
    int size;

public:
    Array(int size = 10)
    {
        this->size = size;
        data = new int[size];

        for (int i = 0; i < size; i++)
            data[i] = 0;
    }

    ~Array()
    {
        delete[] data;
    }

    int &operator[](int index)
    {
        return data[index];
    }

    Array &operator=(const Array &a)
    {
        delete[] data;

        size = a.size;
        data = new int[size];

        for (int i = 0; i < size; i++)
            data[i] = a.data[i];

        return *this;
    }

    bool operator==(const Array &a)
    {
        if (size != a.size)
            return false;

        for (int i = 0; i < size; i++)
        {
            if (data[i] != a.data[i])
                return false;
        }

        return true;
    }

    bool operator!=(const Array &a)
    {
        return !(*this == a);
    }

    friend ostream &operator<<(ostream &out, const Array &a)
    {
        for (int i = 0; i < a.size; i++)
            out << a.data[i] << " ";

        return out;
    }
};

int main()
{
    Array a1(10), a2(10), a3(10);
    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 3;
    a1[3] = 4;
    a2[0] = 1;
    a2[1] = 2;
    a2[2] = 3;
    a2[3] = 4;
    a3 = a1;
    a3[3] = 5;
    cout << "a1 배열은 : " << a1 << endl;
    cout << "a2 배열은 : " << a2 << endl;
    cout << "a3 배열은 : " << a3 << endl;
    cout << "a1 == a2 을 중복 정의 : " << (a1 == a2) << endl;
    cout << "a1 != a3 을 중복 정의 : " << (a1 != a3) << endl;
    cout << "a3 = a1 을 중복 정의 : " << (a3 = a1) << endl;
    return 0;
}
