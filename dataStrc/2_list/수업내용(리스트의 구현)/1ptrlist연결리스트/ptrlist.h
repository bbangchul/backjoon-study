// [알고리즘 C.4] ptrlist.h
class node
{
public:
    node(int d, node *n = 0)
    {
        next_ = n;
        data_ = d;
    }
    // private: 코딩상의 편의를 위하여 모두 public으로 한다.
    node *next_;
    int data_;
};

class list
{
public:
    list();
    int GetSize();
    int GetAt(int index);
    int Index(int key);
    void Insert(int item);
    void Delete(int key);
    int Find(int key);

private:
    node *lst_;
};
