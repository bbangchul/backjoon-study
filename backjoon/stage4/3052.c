#include <stdio.h>

int main(void)
{

    int arr[10];
    int count_one = 0, count = 0;
    int seen[42] = {0};

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        int remainder = arr[i] % 42;
        seen[remainder] = 1;
    }

    // 중복 갯수 구하기
    for (int i = 0; i < 42; i++)
    {
        if (seen[i] == 1)
            count++;
    }
    printf("%d", count);
}
