#include <iostream>
using namespace std;

// Full 예외 클래스
class FullStack
{

private:
    int top;
    int size;

public:
    FullStack(int t, int s)
        : top(t), size(s) {}

    void Show()
    {

        cout << "stack full -> "
             << "stack size : "
             << size
             << " top : "
             << top
             << endl;
    }
};

// Empty 예외 클래스
class EmptyStack
{

private:
    int top;
    int size;

public:
    EmptyStack(int t, int s)
        : top(t), size(s) {}

    void Show()
    {

        cout << "stack empty -> "
             << "stack size : "
             << size
             << " top : "
             << top
             << endl;
    }
};

// Stack 템플릿 클래스
template <typename T>
class Stack
{

private:
    T *s;

    int size;
    int top;

public:
    Stack(int n = 100)
        : size(n), top(-1)
    {
        s = new T[size];
    }

    ~Stack()
    {
        delete[] s;
    }

    bool isEmpty() const
    {

        return top == -1;
    }

    bool isFull() const
    {

        return top == size - 1;
    }

    void push(T v);

    T pop();
};

// push
template <typename T>
void Stack<T>::push(T v)
{

    if (isFull())
    {

        throw FullStack(top, size);
    }

    s[++top] = v;
}

// pop
template <typename T>
T Stack<T>::pop()
{

    if (isEmpty())
    {

        throw EmptyStack(top, size);
    }

    return s[top--];
}

int main()
{

    Stack<int> s;

    try
    {

        s.push(100);
        s.push(200);
        s.push(300);
        s.push(400);

        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;

        // empty 발생
        cout << s.pop() << endl;
    }
    catch (FullStack e)
    {

        e.Show();
    }
    catch (EmptyStack e)
    {

        e.Show();
    }

    return 0;
}