#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int r;
        scanf("%d", &r);

        char a[1001];
        scanf("%s", a);

        for (int i = 0; a[i] != '\0'; i++)
        {
            for (int j = 0; j < r; j++)
            {
                printf("%c", a[i]);
            }
        }
        puts("");
    }
}