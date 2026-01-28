// 진법 변환
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100];
    int b;

    scanf("%s %d", a, &b);

    int la = strlen(a);
    int result = 0;
    int pow = 1;

    for (int i = la - 1; i >= 0; i--)
    {
        int value;

        if ('0' <= a[i] && a[i] <= '9')
            value = a[i] - '0';
        else
            value = a[i] - 'A' + 10;
        result += value * pow;
        pow *= b;
    }

    printf("%d\n", result);

    return 0;
}