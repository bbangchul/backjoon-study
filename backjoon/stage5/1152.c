#include <stdio.h>

int main(void)
{
    char s[1000001];
    int count = 0;

    fgets(s, sizeof(s), stdin);

    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c[%d], count : %d\n", s[i], i, count);
        if (s[i] != ' ' && s[i] != '\n' && (i == 0 || s[i - 1] == ' ' || s[i - 1] == '\n'))
        {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}