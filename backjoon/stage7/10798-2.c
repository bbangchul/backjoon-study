#include <stdio.h>

int main()
{
    char a[5][15];

    for (int i = 0; i < 5; i++)
        scanf("%s", a[i]);

    for (int i = 0; i < 15; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (a[k][i] != NULL)
                printf("%c", a[k][i]);
        }
    }

    return 0;
}
