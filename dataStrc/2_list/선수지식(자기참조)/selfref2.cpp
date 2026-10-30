// [알고리즘 B.9] selfref2.cpp
#include <iostream>
using namespace std;

class node
{
public:
    node()
    {
        data = 0;
        next = 0;
    }
    node(int d, node *n = 0)
    {
        data = d;
        next = n;
    }
    int data;
    node *next;
};

int main()
{
    node *start = new node(2);
    start->next = new node(3);
    node *ptr = new node(5);
    start->next->next = ptr;
    ptr = start->next->next;
    ptr->next = new node(7);
    cout << start->next->data;
}
