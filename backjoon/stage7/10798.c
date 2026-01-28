#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char a[16];
    scanf("%s", a);
    char b[16];
    scanf("%s", b);
    char c[16];
    scanf("%s", c);
    char d[16];
    scanf("%s", d);
    char e[16];
    scanf("%s", e);

    char answer[100] = {0};

    int n = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        answer[n] = a[i];
        n += 5;
    }

    n = 1;
    for (int i = 0; b[i] != '\0'; i++)
    {
        answer[n] = b[i];
        n += 5;
    }

    n = 2;
    for (int i = 0; c[i] != '\0'; i++)
    {
        answer[n] = c[i];
        n += 5;
    }

    n = 3;
    for (int i = 0; d[i] != '\0'; i++)
    {
        answer[n] = d[i];
        n += 5;
    }

    n = 4;
    for (int i = 0; e[i] != '\0'; i++)
    {
        answer[n] = e[i];
        n += 5;
    }

    for (int i = 0; i < 100; i++)
    {
        if (answer[i] != 0)
            printf("%c", answer[i]);
    }
}
