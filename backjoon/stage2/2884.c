#include <stdio.h>

int main(void){

    int hour, min;
    scanf("%d %d", &hour, &min);

    if (min >= 45)
    {
        if (hour > 0)
        {
            printf("%d %d", hour, min-45);
        }
        else
        {
            printf("0 %d", min-45);
        } 
    }
    else {
        if (hour > 0)
        {
            printf("%d %d", hour-1, min+15);
        }
        else
        {
            printf("23 %d", min+15);
        }
    }

    
    
    


    
    return 0;
}