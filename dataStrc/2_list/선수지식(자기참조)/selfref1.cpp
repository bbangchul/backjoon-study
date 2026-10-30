// [알고리즘 B.8] selfref1.cpp
#include <iostream>
using namespace std;

class node {
public:
    node() { data=0; next=0; }
    node(int d, node *n=0) { data = d; next = n; }
    int data;
    node * next;
};

int main() {
    node first(2);
    node second(3);
    node third(5);
    first.next = &second;
    second.next = &third;

    cout << (*(first.next)).data << endl;
}
