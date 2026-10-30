// [코드 B.90] 분수 소스코드 (구조체와 함수)
#include <iostream>
using namespace std;

typedef struct {
    int ja;
    int mo;
} fraction;

fraction readFraction(fraction &f) {
    char c;
    cin >> f.ja;
    cin >> c;
    cin >> f.mo;
    return f;
}

void writeFraction(fraction f) {
    cout << f.ja;
    cout << "/";
    cout << f.mo;
}

int GCD(int ja, int mo) {
    for(int i=mo; i>0; i--) {
        if(ja % i == 0 && mo % i == 0) return i;
    }
    return 1;
}

fraction add(fraction fa, fraction fb){
    fraction fc;
    fc.ja = (fa.ja * fb.mo) + (fb.ja * fa.mo);
    fc.mo = (fa.mo * fb.mo);
    int gcd = GCD(fc.ja, fc.mo);
    fc.ja /= gcd;
    fc.mo /= gcd;
    return fc;
}

fraction sub(fraction fa, fraction fb){
    fraction fc;
    fc.ja = (fa.ja * fb.mo) - (fb.ja * fa.mo);
    fc.mo = (fa.mo * fb.mo);
    int gcd = GCD(fc.ja, fc.mo);
    fc.ja /= gcd;
    fc.mo /= gcd;
    return fc;
}

fraction mul(fraction fa, fraction fb)
{
    fraction fc;
    fc.ja = fa.ja * fb.ja;
    fc.mo = (fa.mo * fb.mo);
    int gcd = GCD(fc.ja, fc.mo);
    fc.ja /= gcd;
    fc.mo /= gcd;
    return fc;
}

int main() {
    fraction fa, fb, fc, fd, fe, fg, fh;

    readFraction(fa);
    readFraction(fb);
    readFraction(fc);
    readFraction(fd);
    fe = add(fa, fb);
    fg = sub(fc, fd);
    fh = mul(fe, fg);
    writeFraction(fh);
}
