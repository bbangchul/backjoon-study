// 분수찾기
#include <stdio.h>

int main(void)
{
    long long a, b, v;
    scanf("%lld %lld %lld", &a, &b, &v);

    long long n = v - a;
    if (n <= 0)
    {
        printf("1\n");
        return 0;
    }

    long long day = n / (a - b);
    if (n % (a - b) != 0)
        day++;

    printf("%lld", day + 1);
    return 0;
}