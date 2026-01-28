// 중앙 이동 알고리즘
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    int side = 2;

    for (int i = 0; i < n; i++)
    {
        side += side - 1;
        printf("%d\n", side);
    }

    printf("%d", side * side);
}
