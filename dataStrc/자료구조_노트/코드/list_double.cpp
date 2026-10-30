

#include <iostream>

using namespace std;

class dlnode
{
public:

    dlnode(int d, dlnode *p = 0, dlnode *n = 0)
    {
        prev_ = p;
        next_ = n;
        data_ = d;
    }
    dlnode *prev_;
    dlnode *next_;
    int data_;
};

class dllist
{
public:
    dllist();
    ~dllist();
    dllist(const dllist &) = delete;
    dllist &operator=(const dllist &) = delete;

    void Insert(int item);
    void Delete(int value);

    int Find(int key);
    void Print();
    void PrintReverse();

private:

    dlnode *head_;
    dlnode *tail_;
};

dllist::dllist()
{
    head_ = 0;
    tail_ = 0;
}

void dllist::Insert(int item)
{

    if (head_ == 0)
    {
        head_ = new dlnode(item);
        tail_ = head_;
        return;
    }

    if (item <= head_->data_)
    {
        dlnode *ptr = new dlnode(item, 0, head_);
        head_->prev_ = ptr;
        head_ = ptr;
        return;
    }

    if (tail_->data_ < item)
    {
        dlnode *ptr = new dlnode(item, tail_, 0);
        tail_->next_ = ptr;
        tail_ = ptr;
        return;
    }

    dlnode *ptr = head_;
    while (ptr->data_ < item)
        ptr = ptr->next_;

    dlnode *nptr = new dlnode(item, ptr->prev_, ptr);
    ptr->prev_->next_ = nptr;
    ptr->prev_ = nptr;
}

void dllist::Delete(int value)
{

    dlnode *ptr = head_;
    while (ptr != 0 && ptr->data_ != value)
        ptr = ptr->next_;
    if (ptr == 0)
        return;

    if (ptr->prev_ == 0)
        head_ = ptr->next_;
    else
        ptr->prev_->next_ = ptr->next_;

    if (ptr->next_ == 0)
        tail_ = ptr->prev_;
    else
        ptr->next_->prev_ = ptr->prev_;

    delete ptr;
}

void dllist::Print()
{
    for (dlnode *ptr = head_; ptr != 0; ptr = ptr->next_)
        cout << ptr->data_ << " ";
    cout << endl;
}

void dllist::PrintReverse()
{
    for (dlnode *ptr = tail_; ptr != 0; ptr = ptr->prev_)
        cout << ptr->data_ << " ";
    cout << endl;
}

dllist::~dllist()
{
    while (head_ != 0)
    {
        dlnode *ptr = head_;
        head_ = head_->next_;
        delete ptr;
    }
}

int dllist::Find(int key)
{
    for (dlnode *ptr = head_; ptr != 0; ptr = ptr->next_)
        if (ptr->data_ == key) return 1;
    return 0;
}

int main()
{
    dllist lst;
    lst.Insert(5); lst.Insert(2); lst.Insert(3); lst.Insert(2);
    cout << "Print: "; lst.Print();
    cout << "PrintReverse: "; lst.PrintReverse();
    cout << "Find(3): " << lst.Find(3) << endl;
    lst.Delete(3);
    cout << "Delete(3) 후: "; lst.Print();
}
