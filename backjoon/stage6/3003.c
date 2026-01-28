#include <stdio.h>
#include <string.h>

int main()
{
    int cr[6] = {1, 1, 2, 2, 2, 8};
    int a[6];
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 6; i++)
    {
        int t = 0;
        if (a[i] != cr[i])
        {
            if (t > 0)
            {
                t = cr[i] - a[i];
                a[i] = t;
            }
            else
            {
                t = a[i] - cr[i];
                a[i] = -t;
            }
        }
        else
            a[i] = 0;
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}