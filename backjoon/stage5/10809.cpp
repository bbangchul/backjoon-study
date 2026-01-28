#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char s[101];
    int alpha[26] = {0};
    scanf("%s", s);

    for (int i = 0; i < 26; i++)
    {
        alpha[i] = -1;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        int idx = s[i] - 'a';
        if (alpha[idx] == -1)
        {
            alpha[idx] = i;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%d ", alpha[i]);
    }
}