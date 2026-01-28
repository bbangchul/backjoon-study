// 진법 변환2
#include <stdio.h>
#include <string.h>

int main()
{
    int n, b;
    char a[100];
    int i = 0;

    scanf("%d %d", &n, &b);

    while (n > 0)
    {
        int r = n % b;

        if (r < 10)
            a[i] = '0' + r;
        else
            a[i] = 'A' + (r - 10);

        n /= b;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", a[j]);
    }

    return 0;
}