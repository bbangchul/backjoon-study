#include <iostream>
using namespace std;

int dividePizza(int slices, int persons)
{
    try
    {
        if (persons == 0)
        {
            throw persons;
        }

        return slices / persons;
    }
    catch (int e)
    {
        cout << "dividePizza()에서 먼저 예외 처리" << endl;
        cout << "사람이 " << e << "명입니다." << endl;

        // 받은 예외를 다시 main으로 전달
        throw;
    }
}

int main()
{
    int pizza_slices = 0;
    int persons = -1;
    int slices_per_person = 0;

    try
    {
        cout << "피자 조각 수를 입력하시오: ";
        cin >> pizza_slices;

        cout << "사람수를 입력하시오: ";
        cin >> persons;

        slices_per_person = dividePizza(pizza_slices, persons);

        cout << "한 사람당 피자는 "
             << slices_per_person
             << "입니다." << endl;
    }
    catch (int e)
    {
        cout << "main()에서 다시 예외 처리" << endl;
        cout << "사람이 " << e << "명입니다." << endl;
    }

    return 0;
}