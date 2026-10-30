// [알고리즘 D.13] queue20.h
#include <iostream>

class queue10
{
public:
    queue10() { rear = 0; }
    bool IsEmpty() { return (rear == 0); };
    bool IsFull() { return (rear == 10); };
    bool InsertQ(int el)
    {
        if (rear == 10)
            return false;
        arr[rear++] = el;
        return true;
    }
    int DeleteQ()
    {
        if (rear == 0)
            return -1;
        int el = arr[0];
        rear--;
        for (int i = 0; i < rear; i++)
            arr[i] = arr[i + 1];
        return el;
    }
    void Print()
    {
        for (int i = 0; i < rear; i++)
            std::cout << arr[i] << " ";
    }

private:
    int arr[10];
    int rear;
};

class queue20
{
public:
    queue20();
    ~queue20();
    bool IsEmpty();
    bool IsFull();
    bool InsertQ(int el);
    int DeleteQ();
    void Print();
    void Reverse();

private:
    queue10 qa;
    queue10 *qb;
};
