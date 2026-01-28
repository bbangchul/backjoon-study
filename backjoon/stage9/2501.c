#include <stdio.h>

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);

    int a[100] = {0};
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            a[cnt] = i;
            cnt++;
        }
    }
    if (k <= cnt)
    {
        printf("%d\n", a[k - 1]);
    }
    else
    {
        printf("0\n");
    }
}