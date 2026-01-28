#include <stdio.h>
#include <string.h>

int main(void){

    int arr_size, try_num, i, j, k;

    scanf("%d %d", &arr_size, &try_num);

    int arr[arr_size];
    memset(arr, 0, sizeof arr);

    for (int a = 0; a < try_num; a++)
    {
        scanf("%d %d %d", &i, &j, &k);
        for (int idx = i - 1; idx < j; idx++)
        {
            arr[idx] = k;
        }
    }
    
    for (int b = 0; b < arr_size; b++)
    {
        printf("%d ", arr[b]);
    }
    
}
