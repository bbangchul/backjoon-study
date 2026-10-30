// [알고리즘 E.3] 배열 스택으로 문자열 뒤집기
#include "../1_arrayStack배열스택/stack.h"
#include <iostream>
using namespace std;

int main()
{
    cout << boolalpha;
    Stack test(2);
    cout << "IsEmpty: " << test.IsEmpty() << endl;
    cout << "Push(10): " << test.Push(10) << endl;
    cout << "Push(20): " << test.Push(20) << endl;
    cout << "IsFull: " << test.IsFull() << endl;
    cout << "Top: " << test.Top() << endl;
    cout << "Pop: " << test.Pop() << endl;
    cout << "Pop: " << test.Pop() << endl;
    cout << "IsEmpty: " << test.IsEmpty() << endl;
    cout << "=== 문자열 뒤집기: 한 줄 입력 (최대 30바이트) ===" << endl;
    Stack stack(30);
    char c;
    while (cin.get(c) && c != '\n')
    {
        if (!stack.Push(static_cast<unsigned char>(c)))
        {
            cerr << "입력은 최대 30바이트까지 가능합니다." << endl;
            return 1;
        }
    }
    while (!stack.IsEmpty())
        cout << static_cast<char>(stack.Pop());
    cout << endl;
    return 0;
}
