#include <stdio.h>

int main(void)
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
            break;

        int sum = 0;

        for (int i = 1; i <= n; i++)
        {
            if ((n % i == 0) && (n != i))
            {

                sum += i;
            }
        }

        if (sum != n)
        {
            printf("%d is NOT perfect.\n", n);
        }
        else
        {
            int ck = 0;
            printf("%d = 1", n);

            for (int i = 1; i <= n; i++)
            {
                if ((n % i == 0) && (n != i) && (i != 1))
                {
                    printf(" + %d", i);
                }
            }
            puts("");
        }
    }
}