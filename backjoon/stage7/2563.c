#include <stdio.h>

int main(void)
{
    int a[100][100] = {0};
    int n;
    scanf("%d", &n);

    int x, y;
    while (n--)
    {
        scanf("%d %d", &x, &y);

        for (int i = x; i < x + 10; i++)
        {
            for (int j = y; j < y + 10; j++)
            {
                a[i][j] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (a[i][j] == 1)
                count++;
        }
    }

    printf("%d", count);
}