// [알고리즘 D.7] node.h
#define ERROR -1;
class node
{
public:
    node(int d, node *n = 0)
    {
        nxt_ = n;
        data_ = d;
    }
    // private:
    node *nxt_;
    int data_;
};
