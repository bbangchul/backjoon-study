
// [알고리즘 D.10] 큐의 응용
// 10개의 정수를 읽은 후에, 먼저 음의 정수를 읽은 순서대로 모두 출력하고,
// 이후 나머지 양의 정수를 읽은 순서대로 출력한다. (입력에 0은 없음)
#include <iostream>
using namespace std;

#define MAXQ 100

// 환형큐 (circularQueue와 동일)
class Queue
{
public:
    Queue()
    {
        front_ = 0;
        rear_ = 0;
    }
    bool IsEmpty() { return (rear_ == front_); }
    bool IsFull() { return ((rear_ + 1) % MAXQ == front_); }
    bool InsertQ(int el)
    {
        if (IsFull())
            return false;
        arr_[rear_++] = el;
        rear_ = rear_ % MAXQ;
        return true;
    }
    int DeleteQ()
    {
        if (IsEmpty())
            return -1;
        int el = arr_[front_++];
        front_ = front_ % MAXQ;
        return el;
    }

private:
    int arr_[MAXQ];
    int front_;
    int rear_;
};

int main()
{
    Queue neg, pos;
    int v;

    for (int i = 0; i < 10; i++)
    {
        cin >> v;
        if (v < 0)
            neg.InsertQ(v);
        else
            pos.InsertQ(v);
    }
    while (!neg.IsEmpty())
        cout << neg.DeleteQ() << " ";
    while (!pos.IsEmpty())
        cout << pos.DeleteQ() << " ";
    cout << endl;

    return 0;
}
