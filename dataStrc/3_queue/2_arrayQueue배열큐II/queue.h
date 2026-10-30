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
