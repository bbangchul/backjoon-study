#include <stdio.h>
#include <string.h>

int main()
{

    char a[1000001];
    scanf("%s", a);

    int as[26] = {0};

    int la = strlen(a);

    for (int i = 0; i < la; i++)
    {
        a[i] = a[i] & ~32; // 대문자 변경
        int t = a[i] - 65;
        as[t] += 1;
    }

    int ck = 0;
    int max = -1;
    int cn = 0;
    for (int i = 0; i < 26; i++)
    {
        if (as[i] > max)
        {
            max = as[i];
            ck = i;
            cn = 0;
        }
        else if (as[i] == max)
        {
            cn = 1;
        }
    }

    if (cn)
    {
        printf("?");
    }
    else
    {
        printf("%c", ck + 65);
    }

    return 0;
}