// [코드 B.92] 분수 소스코드 (오퍼레이터 오버로딩)
#include <iostream>
using namespace std;

class fraction {
public:
    void readFraction();
    void writeFraction();
    fraction operator+(fraction rhs);
    fraction operator-(fraction rhs);
    fraction operator*(fraction rhs);
    fraction operator/(fraction rhs);
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
fraction::operator+(fraction rhs) {
    fraction fc;
    fc.ja = (ja * rhs.mo) + (rhs.ja * mo);
    fc.mo = mo * rhs.mo;
    fc.makeIrreducible();
    return fc;
}

fraction
fraction::operator-(fraction rhs) {
    fraction fc;
    fc.ja = (ja * rhs.mo) - (rhs.ja * mo);
    fc.mo = mo * rhs.mo;
    fc.makeIrreducible();
    return fc;
}

fraction
fraction::operator*(fraction rhs) {
    fraction fc;
    fc.ja = ja * rhs.ja;
    fc.mo = mo * rhs.mo;
    fc.makeIrreducible();
    return fc;
}

fraction
fraction::operator/(fraction rhs) { // 0으로 나누는 경우는 없음을 가정한다.
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
//    fe = fa+fb;
//    fg = fc-fd;
//    fh = fe*fg;
    fh = ((fa+fb)*(fc-fd));
    fh.writeFraction();
}
