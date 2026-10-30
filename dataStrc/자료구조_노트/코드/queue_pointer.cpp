
// [알고리즘 D.9] ptrQueue.cpp

// using namespace std; → std::queue와 이름 충돌하므로 사용하지 않음
// [알고리즘 D.7] node.h
class node
{
public:
    node(int d, node *n = 0)
    {
        nxt_ = n;
        data_ = d;
    }
    // private:
    node *nxt_;
    int data_;
};
// 여기까지 node.h
class queue
{
public:
    queue();
    ~queue() { while (!IsEmpty()) DeleteQ(); }
    queue(const queue &) = delete;
    queue &operator=(const queue &) = delete;
    bool IsEmpty();
    bool IsFull();
    void InsertQ(int el);
    int DeleteQ();

private:
    node *front_;
    node *rear_;
};
// 여기까지 ptrQueue.h
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

    delete q;
    return 0;
}
