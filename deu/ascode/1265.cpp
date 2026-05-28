#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int p = 1;

    while (t--)
    {
        string a, b;
        cin >> a >> b;

        string result = "";

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0)
        {
            int bitA = (i >= 0) ? a[i] - '0' : 0;
            int bitB = (j >= 0) ? b[j] - '0' : 0;

            int sum = bitA + bitB + carry;

            result += (sum % 2) + '0';
            carry = sum / 2;

            i--;
            j--;
        }

        if (carry == 1)
        {
            result += '1';
        }

        reverse(result.begin(), result.end());

        int idx = 0;
        while (idx + 1 < result.size() && result[idx] == '0')
        {
            idx++;
        }

        cout << p << ' ' << result.substr(idx) << '\n';
        p++;
    }

    return 0;
}