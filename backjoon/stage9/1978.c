#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int a[100] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        if (x <= 1)
            continue;

        int prime = 1;
        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime)
        {
            count++;
        }
    }

    printf("%d\n", count);
}
