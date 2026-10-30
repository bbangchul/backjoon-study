// [알고리즘 D.5] circularQueue.h
#define MAXQ 100

class Queue {
public:
    Queue();
    bool IsEmpty() { return (rear_ == front_); }
    bool IsFull() { return ((rear_+1) % MAXQ == front_); }
    bool InsertQ(int el);
    int DeleteQ();
private:
    int arr_[MAXQ];
    int front_;
    int rear_;
};

// [알고리즘 D.6] circularQueue.cpp
#include <iostream>
using namespace std;

Queue::Queue() {
    front_ = 0;
    rear_ = 0;
}

bool Queue::InsertQ(int el) {
    if (IsFull()) return false;
    arr_[rear_++] = el;
    rear_ = rear_ % MAXQ;
    return true;
}

int Queue::DeleteQ() {
    if (IsEmpty()) return -1;
    int el = arr_[front_++];
    front_ = front_ % MAXQ;
    return el;
}

int main() {
    Queue * q = new Queue();
    q-> InsertQ(2);
    q-> InsertQ(5);
    q-> InsertQ(3);
    while (!q->IsEmpty()) cout << q->DeleteQ() << " ";
    delete q;
    return 0;
}
