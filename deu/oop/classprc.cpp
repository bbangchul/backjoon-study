#include <iostream>
using namespace std;

class Sample
{
private:
    int value;

public:
    Sample(int v) : value(v) {}

    void set(int v) const
    {
        value = v;
    }

    void show() const
    {
        cout << value << endl;
    }
};

class Tool
{
public:
    void work(Sample *s)
    {
        s->set(10);
    }
};

int main()
{
    Sample s(1);
    Tool t;
    t.work(&s);
    s.show();
    return 0;
}