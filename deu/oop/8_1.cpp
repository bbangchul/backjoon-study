#include <iostream>
using namespace std;

class Gate
{
protected:
    bool x, y;
    bool z;

public:
    Gate()
    {
        x = y = z = false;
    }

    void inputSet(bool xx, bool yy)
    {
        x = xx;
        y = yy;
    }

    virtual void op() = 0;
};

class ANDGate : public Gate
{
public:
    void op()
    {
        z = x && y;
        cout << "AND input : " << x << " " << y << " -> " << z << endl;
    }
};

class ORGate : public Gate
{
public:
    void op()
    {
        z = x || y;
        cout << "OR input : " << x << " " << y << " -> " << z << endl;
    }
};

class XORGate : public Gate
{
public:
    void op()
    {
        z = x ^ y;
        cout << "XOR input : " << x << " " << y << " -> " << z << endl;
    }
};

void p8_1()
{
    ANDGate gate_and;
    ORGate gate_or;
    XORGate gate_xor;

    gate_and.inputSet(true, false);
    gate_and.op();
    gate_and.inputSet(true, true);
    gate_and.op();

    gate_or.inputSet(true, false);
    gate_or.op();
    gate_or.inputSet(true, true);
    gate_or.op();

    gate_xor.inputSet(true, false);
    gate_xor.op();
    gate_xor.inputSet(true, true);
    gate_xor.op();
}

int main()
{
    p8_1();
    return 0;
}