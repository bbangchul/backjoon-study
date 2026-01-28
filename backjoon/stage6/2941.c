#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    scanf("%s", a);

    int count = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        switch (a[i])
        {
        case 'c':
            if (a[i + 1] == '=' || a[i + 1] == '-')
            {
                count++;
                i++;
                continue;
            }
            break;

        case 'd':
            if (a[i + 1] == 'z' && a[i + 2] == '=')
            {
                count++;
                i += 2;
                continue;
            }
            if (a[i + 1] == '-')
            {
                count++;
                i++;
                continue;
            }
            break;

        case 'l':
            if (a[i + 1] == 'j')
            {
                count++;
                i++;
                continue;
            }
            break;

        case 'n':
            if (a[i + 1] == 'j')
            {
                count++;
                i++;
                continue;
            }
            break;

        case 's':
            if (a[i + 1] == '=')
            {
                count++;
                i++;
                continue;
            }
            break;

        case 'z':
            if (a[i + 1] == '=')
            {
                count++;
                i++;
                continue;
            }
            break;

        default:
            break;
        }

        count++;
    }

    printf("%d", count);

    return 0;
}