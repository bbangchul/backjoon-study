// [알고리즘 D.8] ptrQueue.h
#include "node.h"
class queue {
public:
    queue();
    bool IsEmpty();
    bool IsFull();
    void InsertQ(int el);
    int DeleteQ();
private:
    node * front_;
    node * rear_;
};
