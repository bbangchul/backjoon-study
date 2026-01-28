// 벌집
#include <stdio.h>

int main()
{
    long long n;
    scanf("%lld", &n);

    long long max = 1;
    int count = 1;
    while (n > max)
    {
        max = max + count * 6;
        count++;
    }
    printf("%d", count);
    return 0;
}
