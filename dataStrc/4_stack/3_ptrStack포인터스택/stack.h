// [알고리즘 E.6]
#ifndef POINTER_STACK_H
#define POINTER_STACK_H
#include "node.h"

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

#endif
