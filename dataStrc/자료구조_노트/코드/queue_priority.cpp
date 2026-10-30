// [알고리즘 D.7] PQ의 구현
// 강의 코드에서 "구현이 있다고 가정"한 orderedList를 간단히 구현하여 포함함.

class node
{
public:
    node(int d, node *n = 0)
    {
        nxt_ = n;
        data_ = d;
    }
    // private: 코딩상의 편의를 위하여 모두 public으로 한다.
    node *nxt_;
    int data_;
};

class orderedList
{ // 오름차순으로 정렬된 연결리스트
public:
    orderedList() { lst_ = 0; }
    ~orderedList()
    {
        while (lst_ != 0)
        {
            node *ptr = lst_;
            lst_ = lst_->nxt_;
            delete ptr;
        }
    }
    orderedList(const orderedList &) = delete;
    orderedList &operator=(const orderedList &) = delete;
    int GetSize()
    {
        int n = 0;
        for (node *p = lst_; p != 0; p = p->nxt_)
            n++;
        return n;
    }
    void Insert(int item)
    {
        if (lst_ == 0 || item < lst_->data_)
        {
            lst_ = new node(item, lst_);
            return;
        }
        node *p = lst_;
        while (p->nxt_ != 0 && p->nxt_->data_ <= item)
            p = p->nxt_;
        p->nxt_ = new node(item, p->nxt_);
    }
    void Delete(int value)
    {
        if (lst_ == 0)
            return;
        node *ptr;
        if (lst_->data_ == value)
        {
            ptr = lst_;
            lst_ = lst_->nxt_;
            delete ptr;
            return;
        }
        node *p = lst_;
        while (p->nxt_ != 0 && p->nxt_->data_ != value)
            p = p->nxt_;
        if (p->nxt_ == 0)
            return;
        ptr = p->nxt_;
        p->nxt_ = ptr->nxt_;
        delete ptr;
    }
    int GetAt(int index)
    {
        node *p = lst_;
        for (int i = 0; i < index && p != 0; i++)
            p = p->nxt_;
        if (p == 0)
            return -1;
        return p->data_;
    }
    int Index(int key)
    {
        int i = 0;
        for (node *p = lst_; p != 0; p = p->nxt_, i++)
            if (p->data_ == key)
                return i;
        return -1;
    }

private:
    node *lst_;
};

class priorityQueue
{
public:
    priorityQueue()
    {
        ol_ = new orderedList();
    }
    ~priorityQueue() { delete ol_; }
    priorityQueue(const priorityQueue &) = delete;
    priorityQueue &operator=(const priorityQueue &) = delete;
    bool IsEmpty()
    {
        return ol_->GetSize() == 0;
    };
    bool IsFull()
    { // 리스트의 포인터구현에서는 full 이 없음을 가정
        return false;
    };
    bool InsertQ(int el)
    {
        ol_->Insert(el);
        return true;
    };
    int DeleteQ()
    { // list의 Delete()의 리턴타입이 int인 경우 더 간단
        int item = ol_->GetAt(0);
        ol_->Delete(item);
        return item;
    }

private:
    orderedList *ol_;
};

// [알고리즘 D.8] PQ의 응용 sorting
// priorityQueue의 구현이 priorityQueue.h에 있다고 가정함.
#include <iostream>
using namespace std;

int main() {
    priorityQueue pq;
    int v;

    for (int i=0; i<7; i++) {
        cin >> v;
        pq.InsertQ(v);
    }
    while(!pq.IsEmpty()) {
        cout << pq.DeleteQ() << " ";
    }
    cout << endl;
}
