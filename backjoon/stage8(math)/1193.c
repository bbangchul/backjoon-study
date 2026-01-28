// 분수찾기
#include <stdio.h>

int main(void)
{
    long long n;
    scanf("%lld", &n);

    int up, dn;

    int p;              // 대각선 번호(candidate)
    long long sum = 0;  // 대각선 누적합
    long long prev = 0; // 직전 대각선까지의 누적합
    long long pos = 0;  // 대각선 안에서의 위치

    p = 1;
    while (sum < n)
    {
        sum += p;
        p++;
    }
    p--;

    prev = sum - p;
    pos = n - prev;

    if (p % 2 == 1)
    {
        up = p - pos + 1;
        dn = pos;
    }
    else
    {
        up = pos;
        dn = p - pos + 1;
    }

    printf("%d/%d\n", up, dn);

    return 0;
}