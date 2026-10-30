// [알고리즘 C.6] dllist.h
class dlnode
{ // 이름의 충돌이 없다면, 이름을 node로 수정해도 좋음
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
{ // 이름의 충돌이 없다면, 이름을 list로 수정해도 좋음
public:
    dllist();
    //    int GetSize();
    void Insert(int item);
    void Delete(int value);
    //    int GetAt(int position);
    //    int Index(int value);    // index Rank(key item);
    int Find(int key);
    void Print();
    void PrintReverse();

private:
    dlnode *head_;
    dlnode *tail_;
};
