// [알고리즘 D.1] queue.h
#define MAXQ 100

class Queue {
public:
    Queue();
    bool IsEmpty() { return (rear_==front_); }
    bool IsFull() { return (rear_==MAXQ); }
    bool InsertQ(int el);
    int DeleteQ();
private:
    int arr_[MAXQ];
    int front_;
    int rear_;
};
