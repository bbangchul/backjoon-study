#include <stdio.h>

int main(void)
{
    int a[9][9];

    int max = 0, max_i = 0, max_j = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] > max)
            {
                max = a[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    printf("%d\n%d %d", max, max_i + 1, max_j + 1);
}