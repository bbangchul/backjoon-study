#include <iostream>
using namespace std;

template <typename T1, typename T2>
void copyy(T1 a[], T2 b[], int n)
{

    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

int main()
{

    int a[] = {1, 2, 3, 4, 5};

    float x[5];

    copyy(x, a, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << x[i] << " ";
    }

    cout << endl;

    return 0;
}