#include <stdio.h>

int main(void){

    int cur_hour, cur_min, req_min, total_min, total_sum_hour, total_sum_min;
    scanf("%d %d\n", &cur_hour, &cur_min);
    scanf("%d", &req_min);

    total_min = cur_hour * 60 + cur_min;
    total_sum_hour = (total_min + req_min) / 60;
    total_sum_min = (total_min + req_min) % 60;

    if (total_sum_hour < 24)
    {
        printf("%d %d", total_sum_hour, total_sum_min);
    }
    else
    {
        printf("%d %d", total_sum_hour % 24, total_sum_min);
    }
    
}