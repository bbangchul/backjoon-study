#include <iostream>
using namespace std;

int main()
{
    int pizza_slices = 0;
    int persons = -1;
    int slices_per_person = 0;

    while (1)
    {
        try
        {
            cout << "피자 조각 수를 입력하시오: ";
            cin >> pizza_slices;

            cout << "사람수를 입력하시오: ";
            cin >> persons;

            if (persons == 0)
            {
                throw persons;
            }
        }
        catch (int e)
        {
            cout << "사람이 " << e << "명입니다." << endl;
        }

        // 잘못된 위치
        // persons가 0이어도 catch 이후에 다시 나눗셈을 수행함
        slices_per_person = pizza_slices / persons;

        cout << "한 사람당 피자는 "
             << slices_per_person
             << "입니다." << endl;
    }

    return 0;
}