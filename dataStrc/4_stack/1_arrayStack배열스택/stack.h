// [알고리즘 E.1] 배열 스택
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class Stack
{
public:
    Stack(int s = 100)
    {
        size = s;
        storage = new int[size];
        top = 0; // 다음에 삽입할 위치이자 현재 원소 개수
    }
    ~Stack() { delete[] storage; }
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;

    bool IsEmpty() { return top == 0; }
    bool IsFull() { return top == size; }
    bool Push(int el);
    int Pop();
    int Top();

private:
    int *storage;
    int top;
    int size;
};

#endif
