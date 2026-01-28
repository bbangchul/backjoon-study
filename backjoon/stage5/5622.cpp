#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

    char s[16];
    scanf("%s", s);

    int ls = strlen(s);
    int t = 0;

    for (int i = 0; i < ls; i++)
    {
        int n = s[i];
        // printf("%d\n", n);
        if (n >= 87 && n <= 92)
            t += 10;
        else if (n >= 'T' && n <= 'V')
            t += 9;
        else if (n >= 'P' && n <= 'S')
            t += 8;
        else if (n >= 'M' && n <= 'O')
            t += 7;
        else if (n >= 'J' && n <= 'L')
            t += 6;
        else if (n >= 'G' && n <= 'I')
            t += 5;
        else if (n >= 'D' && n <= 'F')
            t += 4;
        else if (n >= 'A' && n <= 'C')
            t += 3;
    }
    printf("%d", t);
}
