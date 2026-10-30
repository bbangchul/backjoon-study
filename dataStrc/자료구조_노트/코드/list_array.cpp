
// [알고리즘 C.3] list.cpp
#include <iostream>
using namespace std;
class list
{
public:
    list(int lsize = 100);
    ~list() { delete[] arr; }
    list(const list &) = delete;
    list &operator=(const list &) = delete;
    int GetSize();
    int GetAt(int index);
    int Index(int key); // index Rank(key item);
    void Insert(int item);
    void Delete(int key);
    int Find(int value);

private:
    int LMAX;
    int *arr;
    int size;
};
// 여기까지 list.h

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
