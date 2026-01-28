#include <stdio.h>
#include <string.h>

int main()
{
    char word[101];
    scanf("%s", word);

    printf("%lu", strlen(word));

    // int len = 0
    // while (word[len] != '\0')
    // {
    //     len++;
    // }

    return 0;
}