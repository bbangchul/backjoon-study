// 세탁소 사장 동혁
#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int c;
        scanf("%d", &c);

        int a[4] = {0};

        a[0] = c / 25;
        int r = c % 25;
        a[1] = r / 10;
        r = r % 10;
        a[2] = r / 5;
        r = r % 5;
        a[3] = r;

        for (int i = 0; i < 4; i++)
        {
            printf("%d ", a[i]);
        }
        puts("");
    }
}