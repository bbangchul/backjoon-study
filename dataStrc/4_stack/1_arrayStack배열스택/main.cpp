#include <iostream>
using namespace std;

// ===== stack.h 영역 시작 =====
// [알고리즘 E.1] 배열 스택

class Stack
{
public:
    Stack(int s = 100)
    {
        size = s;
        storage = new int[size];
        top = 0; // 다음에 삽입할 위치이자 현재 원소 개수
    }
    ~Stack() { delete[] storage; }
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;

    bool IsEmpty() { return top == 0; }
    bool IsFull() { return top == size; }
    bool Push(int el);
    int Pop();
    int Top();

private:
    int *storage;
    int top;
    int size;
};
// ===== 여기까지 stack.h 영역 =====

// ===== stack.cpp 영역 시작 =====
// [알고리즘 E.2]

bool Stack::Push(int el)
{
    if (IsFull())
        return false;
    storage[top++] = el;
    return true;
}

int Stack::Pop()
{
    if (IsEmpty())
        return 0;
    return storage[--top];
}

int Stack::Top()
{
    if (IsEmpty())
        return 0;
    return storage[top - 1];
}
// ===== 여기까지 stack.cpp 영역 =====

// ===== 실행 예제 영역 시작 =====
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
    return 0;
}
