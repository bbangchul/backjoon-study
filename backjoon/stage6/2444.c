#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < i + (i - 1); j++)
        {
            printf("*");
        }
        puts("");
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < i + (i - 1); j++)
        {
            printf("*");
        }
        puts("");
    }

    return 0;
}