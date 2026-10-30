// [알고리즘 D.2] queue.cpp
#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
    front_ = 0;
    rear_ = 0;
}

bool Queue::InsertQ(int el)
{
    if (rear_ == MAXQ)
        return false; // if(IsFull()) return false;
    arr_[rear_++] = el;
    return true;
}

int Queue::DeleteQ()
{
    if (rear_ == front_)
        return -1; // if(IsEmpty()) return ERROR
    return arr_[front_++];
}

int main()
{
    Queue *q = new Queue();
    q->InsertQ(2);
    q->InsertQ(5);
    q->InsertQ(3);
    while (!q->IsEmpty())
        cout << q->DeleteQ() << " ";

    return 0;
}
