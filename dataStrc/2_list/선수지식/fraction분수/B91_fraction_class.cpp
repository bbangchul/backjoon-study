// [코드 B.91] 분수 소스코드 (클래스)
#include <iostream>
using namespace std;

class fraction {
public:
    void readFraction();
    void writeFraction();
    fraction add(fraction rhs);
    fraction sub(fraction rhs);
    fraction mul(fraction rhs);
    fraction div(fraction rhs);
    void makeIrreducible();
private:
    int ja;
    int mo;
};

void
fraction::readFraction() { // 분모가 0인 경우는 없음을 가정한다.
    char c;
    cin >> ja;
    cin >> c;
    cin >> mo;
}

void
fraction::writeFraction() {
    cout << ja;
    cout << "/";
    cout << mo;
}

void
fraction::makeIrreducible() {
    int i;
    for(i=mo; i>0; i--) {
        if(ja % i == 0 && mo % i == 0) break;
    }
    ja /= i;
    mo /= i;
}

fraction
fraction::add(fraction rhs) {
    fraction fc;
    fc.ja = (ja * rhs.mo) + (rhs.ja * mo);
    fc.mo = mo * rhs.mo;
    fc.makeIrreducible();
    return fc;
}

fraction
fraction::sub(fraction rhs) {
    fraction fc;
    fc.ja = (ja * rhs.mo) - (rhs.ja * mo);
    fc.mo = mo * rhs.mo;
    fc.makeIrreducible();
    return fc;
}

fraction
fraction::mul(fraction rhs) {
    fraction fc;
    fc.ja = ja * rhs.ja;
    fc.mo = mo * rhs.mo;
    fc.makeIrreducible();
    return fc;
}

fraction
fraction::div(fraction rhs) { // 0으로 나누는 경우는 없음을 가정한다.
    fraction fc;
    fc.ja = ja * rhs.mo;
    fc.mo = mo * rhs.ja;
    fc.makeIrreducible();
    return fc;
}

int main() {
    fraction fa, fb, fc, fd, fe, fg, fh;

    fa.readFraction();
    fb.readFraction();
    fc.readFraction();
    fd.readFraction();
    fe = fa.add(fb);
    fg = fc.sub(fd);
    fh = fe.mul(fg);
    fh.writeFraction();
}
