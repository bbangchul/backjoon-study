#include <stdio.h>
#include <string.h>

int main()
{
    char word[101] = "";
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int last_word;
        scanf("%s", word);
        last_word = strlen(word) - 1;
        printf("%c%c\n", word[0], word[last_word]);
    }

    return 0;
}