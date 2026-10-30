// [알고리즘 D.6] circularQueue.cpp
#include "circularQueue.h"
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

    return 0;
}
