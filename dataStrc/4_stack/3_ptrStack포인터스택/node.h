// [알고리즘 E.5]
#ifndef STACK_NODE_H
#define STACK_NODE_H

class node
{
public:
    node(int d, node *n = 0)
    {
        next = n;
        data = d;
    }
    // 학습 편의를 위해 모두 public으로 둔다.
    node *next;
    int data;
};

#endif
