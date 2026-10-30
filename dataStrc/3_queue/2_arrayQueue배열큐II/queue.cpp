// [알고리즘 D.4] queue.cpp
#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
    rear_ = 0;
}

bool Queue::InsertQ(int el)
{
    if (IsFull())
        return false;
    arr_[rear_++] = el;
    return true;
}

int Queue::DeleteQ()
{
    if (IsEmpty())
        return -1;
    int el = arr_[0];
    rear_--;
    for (int i = 0; i < rear_; i++)
        arr_[i] = arr_[i + 1];
    return el;
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
