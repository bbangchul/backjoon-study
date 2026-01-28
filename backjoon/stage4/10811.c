#include <stdio.h>

int main(void)
{

    int n, m; // n : 바구니 갯수, m : 바구니 순서를 바꿀 횟수
    scanf("%d %d", &n, &m);
    int bucket[100];

    for (int i = 0; i <= n; i++)
    {
        bucket[i] = i + 1;
    }

    for (int ig = 0; ig < m; ig++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        int left = a - 1;
        int right = b - 1;
        while (left < right)
        {
            int tmp = bucket[left];
            bucket[left] = bucket[right];
            bucket[right] = tmp;
            left++;
            right--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", bucket[i]);
    }
}