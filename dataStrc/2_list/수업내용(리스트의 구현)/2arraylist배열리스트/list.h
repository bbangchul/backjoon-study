// [알고리즘 C.2] list.h
class list {
public:
    list(int lsize=100);
    int GetSize();
    int GetAt(int index);
    int Index(int key);    // index Rank(key item);
    void Insert(int item);
    void Delete(int key);
    int Find(int value);
private:
    int LMAX;
    int * arr;
    int size;
};
