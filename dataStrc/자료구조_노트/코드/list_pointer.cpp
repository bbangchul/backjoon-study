
// [알고리즘 C.5] ptrlist.cpp
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

class list
{
public:
    list();
    ~list();
    list(const list &) = delete;
    list &operator=(const list &) = delete;
    int GetSize();
    int GetAt(int index);
    int Index(int key);
    void Insert(int item);
    void Delete(int key);
    int Find(int key);

private:
    node *lst_;
};
// 여기까지 ptrlist.h

list::list()
{
    lst_ = 0;
    // size_= 0;
}

int list::GetSize()
{
    node *ptr = lst_;
    int count = 0;
    while (ptr != 0)
    {
        ptr = ptr->nxt_;
        count++;
    }
    return count;
}

int list::GetAt(int index)
{
    if (index < 0) return -1;
    node *ptr = lst_;
    for (int i = 0; i < index; i++)
    {
        if (ptr == 0)
            return -1;
        ptr = ptr->nxt_;
    }
    return ptr == 0 ? -1 : ptr->data_;
}

int list::Index(int key)
{
    node *ptr = lst_;
    int idx = 0;
    while (ptr != 0)
    {
        if (ptr->data_ == key)
            return idx;
        ptr = ptr->nxt_;
        idx++;
    }
    return -1;
}

void list::Insert(int item)
{
    if (lst_ == 0)
    {
        lst_ = new node(item, 0);
        return;
    }
    if (item < lst_->data_)
    {
        lst_ = new node(item, lst_);
        return;
    }
    node *ptr = lst_;
    while (ptr->nxt_ != 0 && ptr->nxt_->data_ < item)
    {
        ptr = ptr->nxt_;
    }
    ptr->nxt_ = new node(item, ptr->nxt_);
}



void list::Delete(int key)
{
    node *ptr = lst_;
    if (lst_ == 0)
        return;
    if (lst_->data_ == key)
    {
        lst_ = lst_->nxt_;
        delete ptr;
        return;
    }
    while (ptr->nxt_ != 0 && ptr->nxt_->data_ != key)
    {
        ptr = ptr->nxt_;
    }
    if (ptr->nxt_ == 0)
        return;
    node *dptr = ptr->nxt_;
    ptr->nxt_ = ptr->nxt_->nxt_;
    delete dptr;
}



#include <iostream>
using namespace std;

list::~list()
{
    while (lst_ != 0)
    {
        node *ptr = lst_;
        lst_ = lst_->nxt_;
        delete ptr;
    }
}

int list::Find(int key)
{
    return Index(key) != -1;
}

int main()
{
    list lst;
    lst.Insert(5); lst.Insert(2); lst.Insert(3);
    cout << "GetSize: " << lst.GetSize() << endl;
    cout << "GetAt(1): " << lst.GetAt(1) << endl;
    cout << "Index(5): " << lst.Index(5) << endl;
    cout << "Find(3): " << lst.Find(3) << endl;
    lst.Delete(3);
    cout << "Delete(3) 후: ";
    for (int i = 0; i < lst.GetSize(); i++) cout << lst.GetAt(i) << " ";
    cout << endl;
}
