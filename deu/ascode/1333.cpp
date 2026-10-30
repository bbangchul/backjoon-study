#include <iostream>
#include <string>

using namespace std;

string trimLeadingZeros(const string &s)
{
    int idx = 0;

    while (idx + 1 < (int)s.size() && s[idx] == '0')
    {
        idx++;
    }

    return s.substr(idx);
}

int compareStringNumber(const string &a, const string &b)
{
    if (a.size() != b.size())
    {
        return (a.size() < b.size()) ? -1 : 1;
    }

    if (a == b)
    {
        return 0;
    }

    return (a < b) ? -1 : 1;
}

string subtractStringNumber(string a, const string &b)
{
    int i = a.size() - 1;
    int j = b.size() - 1;
    int borrow = 0;

    while (i >= 0)
    {
        int digitA = (a[i] - '0') - borrow;
        int digitB = (j >= 0) ? b[j] - '0' : 0;

        if (digitA < digitB)
        {
            digitA += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        a[i] = char(digitA - digitB + '0');
        i--;
        j--;
    }

    return trimLeadingZeros(a);
}

string divideStringNumber(string dividend, const string &divisor)
{
    if (divisor == "0")
    {
        return "undefined";
    }

    dividend = trimLeadingZeros(dividend);

    if (compareStringNumber(dividend, divisor) < 0)
    {
        return "0";
    }

    string quotient = "";
    string current = "";

    for (char ch : dividend)
    {
        current += ch;
        current = trimLeadingZeros(current);

        int count = 0;
        while (compareStringNumber(current, divisor) >= 0)
        {
            current = subtractStringNumber(current, divisor);
            count++;
        }

        quotient += char(count + '0');
    }

    return trimLeadingZeros(quotient);
}

void solve()
{
    string m, n;
    cin >> m >> n;

    m = trimLeadingZeros(m);
    n = trimLeadingZeros(n);

    cout << divideStringNumber(m, n) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
