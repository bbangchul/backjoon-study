#include <stdio.h>

int main(void){

    long long total_amount = 0, user_amount;
    int count, price=0, item_count=0;
    scanf("%lld\n %d", &user_amount,&count);
    for (int i = 0; i < count; i++)
    {
        scanf("%d %d", &price, &item_count);
        total_amount += price*item_count;
    }
    
    if (total_amount == user_amount)
    {
        printf("Yes");
    }
    else
        printf("No");
}