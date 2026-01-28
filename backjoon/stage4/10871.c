#include<stdio.h>

int main(void){

    int size, compare_num, count=0;
    scanf("%d %d", &size, &compare_num);
    int arr[size], compare_arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < compare_num)
        {
            compare_arr[count] = arr[i];
            count++;
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d ", compare_arr[i]);
    }

    return 0;
}

