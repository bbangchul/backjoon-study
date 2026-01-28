#include <stdio.h>
#include <string.h>

double rt(const char *p)
{
    switch (p[0])
    {
    case 'A':
        if (p[1] == '+')
            return 4.5;
        return 4.0;

    case 'B':
        if (p[1] == '+')
            return 3.5;
        return 3.0;

    case 'C':
        if (p[1] == '+')
            return 2.5;
        return 2.0;

    case 'D':
        if (p[1] == '+')
            return 1.5;
        return 1.0;

    case 'F':
        return 0.0;

    default:
        return 0.0;
    }
}

int main(void)
{
    char a[50];
    double sc = 0, gd = 0;
    char b[3];

    double sum = 0;
    int count = 0;
    for (int i = 0; i < 20; i++)
    {
        scanf("%s %lf %s", a, &sc, b);
        if (b[0] == 'P')
            continue;
        else
        {
            gd = rt(b);
            sum += sc * gd;
            count += sc;
        }
    }

    printf("%f", sum / count);

    return 0;
}