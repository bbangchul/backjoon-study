// [알고리즘 C.3] list.cpp
#include "list.h"
#include <iostream>
using namespace std;


list::list(int lsize)
{
    arr = new int[lsize];
    LMAX = lsize;
    size = 0;
}

int list::GetSize()
{
    return size;
}

int list::GetAt(int position)
{
    if (position < 0 || size <= position)
        return -1;
    return arr[position];
}

int list::Index(int value)
{
    for (int i = 0; i < size; i++)
        if (value == arr[i])
            return i;
    return -1;
}

int list::Find(int value)
{
    return Index(value) != -1;
}

void list::Insert(int item)
{
    int i;
    if (size == LMAX)
        return;
    for (i = size; 0 < i; i--)
    {
        if (item < arr[i - 1])
            arr[i] = arr[i - 1];
        else
            break;
    }
    arr[i] = item;
    size++;
}

void list::Delete(int value)
{
    int i;
    for (i = 0; i < size; i++)
        if (value == arr[i])
            break;
    if (i == size)
        return;
    size--;
    for (; i < size; i++)
        arr[i] = arr[i + 1];
}

int main()
{
    list *lst = new list();
    lst->Insert(2);
    lst->Insert(3);
    lst->Insert(5);
    lst->Insert(7);
    cout << lst->GetSize();
}
