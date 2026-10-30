// [알고리즘 E.7]
#include "stack.h"

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
