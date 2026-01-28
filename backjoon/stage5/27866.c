#include <stdio.h>

int main(void)
{
    char word[1001] = "";
    scanf("%s", word);

    int num;
    scanf("%d", &num);

    printf("%c", word[num - 1]);
}