#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char a[100], b[100];
    scanf("%s %s", a, b);
    for (int i = 0; i < strlen(a) / 2; i++)
    {
        char temp = a[i];
        a[i] = a[strlen(a) - 1 - i];
        a[strlen(a) - 1 - i] = temp;
    }

    for (int i = 0; i < strlen(b) / 2; i++)
    {
        char temp = b[i];
        b[i] = b[strlen(b) - 1 - i];
        b[strlen(b) - 1 - i] = temp;
    }

    int na, nb;
    na = atoi(a);
    nb = atoi(b);

    if (na > nb)
        printf("%d", na);
    if (na < nb)
        printf("%d", nb);
}