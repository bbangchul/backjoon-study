#include<stdio.h>

// 백준 2562: 9개의 정수를 입력받아 최댓값과 그 위치를 출력하는 프로그램

int main(void){

    int arr[9]; // 입력받은 정수를 저장할 배열
    int max_num = 0; // 최댓값 저장용 변수
    int max_index = 0; // 최댓값이 위치한 인덱스

    scanf("%d", &arr[0]); // 첫 번째 값은 미리 입력
    max_num = arr[0]; // 첫 번째 값으로 최댓값을 초기화

    for (int i = 1; i < 9; i++)
    {
        scanf("%d", &arr[i]); // 정수 입력
        if (max_num < arr[i])
        {
           max_num = arr[i]; // 새로운 최댓값으로 갱신
           max_index = i; // 최댓값이 위치한 인덱스 저장
        }
    }

    printf("%d\n", max_num); // 최댓값 출력
    printf("%d", max_index+1); // 문제에서 1부터 시작하는 위치를 요구하므로 +1

}
