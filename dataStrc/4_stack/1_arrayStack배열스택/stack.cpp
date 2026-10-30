// [알고리즘 E.2]
#include "stack.h"

bool Stack::Push(int el)
{
    if (IsFull()) return false;
    storage[top++] = el;
    return true;
}

int Stack::Pop()
{
    if (IsEmpty()) return 0;
    return storage[--top];
}

int Stack::Top()
{
    if (IsEmpty()) return 0;
    return storage[top - 1];
}
