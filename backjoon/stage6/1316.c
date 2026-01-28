#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int count = 0;

    while (n--)
    {
        char a[101];
        scanf("%s", a);

        int la = strlen(a);

        int seen[26] = {0};
        int prv = a[0];

        seen[prv - 97] = 1;

        int ck = 1;

        for (int i = 1; i < la; i++)
        {
            if (a[i] != prv)
            {
                if (seen[a[i] - 97] == 1)
                {
                    ck = 0;
                    break;
                }
                seen[a[i] - 97] = 1;
                prv = a[i];
            }
        }
        if (ck)
            count++;
    }

    printf("%d", count);

    return 0;
}