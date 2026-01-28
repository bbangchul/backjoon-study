#include<stdio.h>

int main(void){

    int n,m; // n: 바구니 총 갯수, m : 바꿀 횟수
    int basket[101];
    int a=0, b=0, temp;

    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++)
    {
        basket[i] = i+1;
    }
    
    for (int i = 0; i < m; i++)
    {
        a = 0;
        b = 0;
        scanf("%d %d", &a, &b);
        
        temp = basket[a-1];
        basket[a-1] = basket[b-1];
        basket[b-1] = temp;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", basket[i]);
    }
    
}