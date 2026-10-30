// [알고리즘 C.5] ptrlist.cpp
#include "ptrlist.h"

#define MAXQ 100

class Queue
{
public:
    Queue();
    bool IsEmpty() { return (rear_ == front_); }
    bool IsFull() { return (rear_ == MAXQ); }
    bool InsertQ(int el);
    int DeleteQ();

private:
    int arr_[MAXQ];
    int front_;
    int rear_;
};

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
        ptr = ptr->next_;
        count++;
    }
    return count;
}

int list::GetAt(int index)
{
    node *ptr = lst_;
    for (int i = 0; i < index; i++)
    {
        if (ptr == 0)
            return -1;
        ptr = ptr->next_;
    }
    return ptr->data_;
}

int list::Index(int key)
{
    node *ptr = lst_;
    int idx = 0;
    while (ptr != 0)
    {
        if (ptr->data_ == key)
            return idx;
        ptr = ptr->next_;
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
    while (ptr->next_ != 0 && ptr->next_->data_ < item)
    {
        ptr = ptr->next_;
    }
    ptr->next_ = new node(item, ptr->next_);
}

/*
void
list::Insert(int item) {
    if (lst_==0) {
        lst = new node(item, 0);
        return;
    }
    if (item < lst_->data) {
        lst = new node(item, lst);
        return;
    }
    node * ptr = lst_->next_;
    node * pptr = lst_;
    while (ptr!=0 && ptr->data < item) {
        pptr = ptr;
        ptr = ptr->next;
    }
    pptr->next = new node(item, ptr->next);
}
*/

void list::Delete(int key)
{
    node *ptr = lst_;
    if (lst_ == 0)
        return;
    if (lst_->data_ == key)
    {
        lst_ = lst_->next_;
        delete ptr;
        return;
    }
    while (ptr->next_ != 0 && ptr->next_->data_ != key)
    {
        ptr = ptr->next_;
    }
    if (ptr->next_ == 0)
        return;
    node *dptr = ptr->next_;
    ptr->next_ = ptr->next_->next_;
    delete dptr;
}

/*
int
list::Delete(int key) {
    node * ptr = lst_;
    int item;
    if (lst_==0) return -1;
    if (key == lst_->data) {
        lst_ = lst_->next_;
        item = ptr->data_;
        delete ptr;
        return item;
    }
    while (ptr->next_!=0 && ptr->next_->data_ != item) {
        ptr = ptr->next_;
    }
    if (ptr->next_==0) return -1;
    node * dptr = ptr->next_;
    ptr->next_ = ptr->next_->next_;
    item = dptr->data_;
    delete dptr;
    return item;
}
*/

#include <iostream>
using namespace std;

int main()
{
    list *lst = new list();
    lst->Insert(2);
    lst->Insert(3);
    lst->Insert(5);
    lst->Insert(7);
    cout << lst->GetSize();
}
