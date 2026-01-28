#include <stdio.h>

int main(void) {
    int size;
    scanf("%d", &size);

    long long arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }

    long long min_num = arr[0];
    long long max_num = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min_num) {
            min_num = arr[i];
        }
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    printf("%lld %lld", min_num, max_num);
    return 0;
}
