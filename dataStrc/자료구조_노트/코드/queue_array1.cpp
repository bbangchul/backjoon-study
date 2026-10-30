
// [알고리즘 D.2] queue.cpp
#include <iostream>
using namespace std;

// [알고리즘 D.1] queue.h
#define MAXQ 100

class Queue
{
public:
    Queue();
    bool IsEmpty() { return (rear_ == front_); }
    bool IsFull() { return (rear_ == MAXQ); }
    bool InsertQ(int el);
    int DeleteQ();

private:
    int arr_[MAXQ];
    int front_;
    int rear_;
};
// 여기까지 queue.h

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

    delete q;
    return 0;
}
