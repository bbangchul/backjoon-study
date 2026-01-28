#include <stdio.h>

int main(void) {
    int size, find_num=0, count=0;
    scanf("%d", &size);      // 배열 크기 입력
    int arr[size];           // VLA (a칸짜리 배열)

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &find_num);

    for (int i = 0; i < size; i++) {
        if (arr[i] == find_num)
            count++;
    }
    printf("%d", count);
    return 0;
}
