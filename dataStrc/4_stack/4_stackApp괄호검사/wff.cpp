// [알고리즘 E.8] 잘 갖춰진 괄호 식의 판별
#include "../3_ptrStack포인터스택/stack.h"
#include <iostream>
using namespace std;

bool Match(char a, char b)
{
    if (a == '(' && b == ')') return true;
    if (a == '[' && b == ']') return true;
    if (a == '{' && b == '}') return true;
    return false;
}

int main()
{
    cout << boolalpha;
    Stack test;
    cout << "IsEmpty: " << test.IsEmpty() << endl;
    cout << "Push(10): " << test.Push(10) << endl;
    cout << "Push(20): " << test.Push(20) << endl;
    cout << "IsFull: " << test.IsFull() << endl;
    cout << "Top: " << test.Top() << endl;
    cout << "Pop: " << test.Pop() << endl;
    cout << "Pop: " << test.Pop() << endl;
    cout << "IsEmpty: " << test.IsEmpty() << endl;
    cout << "=== 괄호 검사: 한 줄 입력 ===" << endl;
    Stack stack;
    char c;
    bool valid = true;
    while (cin.get(c) && c != '\n')
    {
        if (c == '(' || c == '[' || c == '{')
            stack.Push(static_cast<int>(c));
        else if (c == ')' || c == ']' || c == '}')
        {
            if (stack.IsEmpty() || !Match(static_cast<char>(stack.Top()), c))
            {
                valid = false;
                break;
            }
            stack.Pop();
        }
    }
    if (valid && stack.IsEmpty()) cout << "WFF!!" << endl;
    else cout << "Not a WFF!!" << endl;
    return 0;
}
