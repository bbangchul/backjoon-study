#include <stdio.h>

int main(void){

    long long a;
    int num1,num2;
    scanf("%lld", &a);

    for (int i = 1; i < a+1; i++)
    {
        scanf("%d %d", &num1, &num2);
        printf("Case #%d: %d + %d = %d\n", i, num1, num2, num1+num2);
    }
}