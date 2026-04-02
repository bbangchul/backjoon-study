#include <iostream>
using namespace std;
int main()
{
    int *pi, num;
    cin >> num;
    pi = new int[num];
    for (int i = 0; i < num; i++)
        *(pi + i) = i; // 포인터 변수 선언(메모리 할당 없음)
    for (int i = 0; i < num; i++)
        cout << *(pi + i) << '\n'; // 포인터 변수 선언(메모리 할당 없음)
    // 입력받은 개수 의 방을 생성
    // ①동적 메모리 할당
    // ②동적 메모리 사용  pi[i] = i;
    // ③동적 메모리 반납
    delete[] pi;
    return 0;
}

// #include <iostream>
// using namespace std;
// int main()
// {
//     int *pi;
//     pi = new int[10];
//     for (int i = 0; i < 10; i++)
//         pi[i] = i;
//     for (int i = 0; i < 10; i++)
//         cout << pi[i] << endl;
//     delete[] pi;
//     return 0;
//     // 동적 메모리 시작 주소를 가리키는 포인터
//     // ①동적 메모리 할당
//     // ②동적 메모리 사용  *(pi + i)
//     // ③동적 메모리 반납
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int *pi;

//     pi = new int[10];
//     for (int i = 0; i < 10; i++)
//         *(pi + i) = i;
//     for (int i = 0; i < 10; i++)
//         cout << (pi + i) << endl;
//     delete[] pi;

//     return 0;
// }