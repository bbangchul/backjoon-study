#include <stdio.h>

int main(void){

    long long a;
    int num1,num2;
    scanf("%lld", &a);

    for (int i = 0; i < a; i++)
    {
        scanf("%d %d", &num1, &num2);
        printf("%d\n", num1+num2);
    }

}