// [알고리즘 D.3] queue.h
#define MAXQ 100

class Queue {
public:
    Queue();
    bool IsEmpty() { return (rear_==0); }
    bool IsFull() { return (rear_==MAXQ); }
    bool InsertQ(int el);
    int DeleteQ();
private:
    int arr_[MAXQ];
    // int front; 항상 첫번째 원소
    int rear_;
};

// [알고리즘 D.4] queue.cpp
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

    delete q;
    return 0;
}
