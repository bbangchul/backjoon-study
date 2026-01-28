#include <stdio.h>
#include <string.h>

int main()
{

    char s[101];
    scanf("%s", s);

    int ls = strlen(s);

    for (int i = 0; i <= ls / 2; i++)
    {
        if (s[i] != s[ls - i - 1])
        {
            printf("0");
            return 0;
        }
    }

    printf("1");

    return 0;
}