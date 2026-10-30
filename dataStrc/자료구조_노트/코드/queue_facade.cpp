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
    queue20(const queue20 &) = delete;
    queue20 &operator=(const queue20 &) = delete;
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

// [알고리즘 D.14] queue20.cpp
// qa: 앞쪽 10개, qb: 뒤쪽 10개
// 불변식: qb에 원소가 있으면 qa는 항상 가득 차 있다. (순서 유지)
#include <iostream>
using namespace std;

queue20::queue20()
{
    qb = new queue10();
}

queue20::~queue20()
{
    delete qb; // 생성자에서 new 한 qb 해제
}

bool queue20::IsEmpty()
{
    return qa.IsEmpty(); // qa가 비었으면 qb도 비어 있음
}

bool queue20::IsFull()
{
    return qb->IsFull(); // qb가 가득 찼으면 qa도 가득 차 있음
}

bool queue20::InsertQ(int el)
{
    if (IsFull())
        return false; // qa, qb 모두 가득 참
    if (!qa.IsFull())
        return qa.InsertQ(el);
    return qb->InsertQ(el);
}

int queue20::DeleteQ()
{
    if (IsEmpty())
        return -1;
    int el = qa.DeleteQ();
    if (!qb->IsEmpty())
        qa.InsertQ(qb->DeleteQ()); // qb의 맨 앞을 qa의 맨 뒤로 옮김
    return el;
}

void queue20::Print()
{
    cout << "qa: [ ";
    qa.Print();
    cout << "] qb: [ ";
    qb->Print();
    cout << "]" << endl;
}

void queue20::Reverse()
{
    // 전부 꺼내 임시 배열에 담은 뒤, 뒤에서부터 다시 삽입
    // InsertQ를 그대로 쓰므로 불변식(qb에 원소가 있으면 qa는 full)이 유지됨
    int buf[20], n = 0;
    while (!IsEmpty())
        buf[n++] = DeleteQ();
    for (int i = n - 1; i >= 0; i--)
        InsertQ(buf[i]);
}

int main()
{
    queue20 *q = new queue20();
    for (int i = 1; i <= 21; i++)
        if (!q->InsertQ(i))
            cout << i << " 삽입 실패(full)" << endl;
    for (int i = 0; i < 5; i++)
        cout << q->DeleteQ() << " ";
    cout << endl;
    for (int i = 22; i <= 26; i++)
        q->InsertQ(i);
    q->Print();
    q->Reverse();
    cout << "Reverse 후" << endl;
    q->Print();
    while (!q->IsEmpty())
        cout << q->DeleteQ() << " ";
    cout << endl;
    q->Print();

    delete q;
    return 0;
}
