#include <stdio.h>

int main(void)
{
    char line[101];
    while (fgets(line, 101, stdin))
    {
        printf("%s", line);
    }

    return 0;
}