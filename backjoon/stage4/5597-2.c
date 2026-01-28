#include <stdio.h>

int main(void){
    int list[31] = {0}; // 1~30만 사용
    int x;

    for (int i = 0; i < 28; i++) {
        if (scanf("%d", &x) != 1) return 0;
        list[x] = 1;  // 제출됨 표시
    }

    for (int i = 0; i < 28; i++)
    {
        printf("%d ", list[i]);
    }
    

    // 제출 안 한 두 명을 오름차순으로 출력
    for (int i = 1, cnt = 0; i <= 30; i++) {
        if (!list[i]) {
            printf("%d\n", i);
            if (++cnt == 2) break;
        }
    }
    return 0;
}