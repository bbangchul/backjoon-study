// [알고리즘 D.9] ptrQueue.cpp

// using namespace std; → std::queue와 이름 충돌하므로 사용하지 않음
#include "ptrQueue.h"
#include <iostream>
queue::queue()
{
    front_ = 0;
    rear_ = 0;
}

bool queue::IsEmpty()
{
    if (front_ == 0)
        return true;
    return false;
}

bool queue::IsFull()
{
    return false;
}

void queue::InsertQ(int el)
{
    // if (IsFull()) return false;
    if (IsEmpty())
    {
        front_ = rear_ = new node(el);
        return;
    }
    rear_->nxt_ = new node(el);
    rear_ = rear_->nxt_;
}

int queue::DeleteQ()
{
    if (IsEmpty())
        return -1; // ERROR!!
    int el = front_->data_;
    node *ptr = front_;
    front_ = front_->nxt_;
    if (front_ == 0)
        rear_ = 0;
    delete ptr;
    return el;
}

int main()
{
    queue *q = new queue();
    q->InsertQ(2);
    q->InsertQ(5);
    q->InsertQ(3);
    while (!q->IsEmpty())
        std::cout << q->DeleteQ() << " ";

    return 0;
}
