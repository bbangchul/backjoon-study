#include <iostream>
using namespace std;

// ===== node.h 영역 시작 =====
// [알고리즘 E.5]

class node
{
public:
    node(int d, node *n = 0)
    {
        next = n;
        data = d;
    }
    // 학습 편의를 위해 모두 public으로 둔다.
    node *next;
    int data;
};
// ===== 여기까지 node.h 영역 =====

// ===== stack.h 영역 시작 =====
// [알고리즘 E.6]

class Stack
{
public:
    Stack();
    ~Stack();
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;
    bool IsEmpty();
    bool IsFull();
    bool Push(int el);
    int Pop();
    int Top();

private:
    node *top;
};
// ===== 여기까지 stack.h 영역 =====

// ===== stack.cpp 영역 시작 =====
// [알고리즘 E.7]

Stack::Stack()
{
    top = 0;
}

Stack::~Stack()
{
    while (!IsEmpty()) Pop();
}

bool Stack::IsEmpty()
{
    return top == 0;
}

bool Stack::IsFull()
{
    return false; // 고정 용량 제한 없음 (메모리 할당 실패 시 new가 예외 발생)
}

bool Stack::Push(int el)
{
    if (IsFull()) return false;
    top = new node(el, top);
    return true;
}

int Stack::Pop()
{
    if (IsEmpty()) return 0;
    node *ptr = top;
    top = top->next;
    int el = ptr->data;
    delete ptr;
    return el;
}

int Stack::Top()
{
    if (IsEmpty()) return 0;
    return top->data;
}
// ===== 여기까지 stack.cpp 영역 =====

// ===== 실행 예제 영역 시작 =====
// [알고리즘 E.8] 잘 갖춰진 괄호 식의 판별

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
