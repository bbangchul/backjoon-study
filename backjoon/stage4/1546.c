#include <stdio.h>

int main(void)
{
    int subject;
    scanf("%d", &subject);
    int arr[subject];
    double avg[subject];
    int max = 0;
    double sum = 0;

    for (int i = 0; i < subject; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int i = 0; i < subject; i++)
    {
        avg[i] = ((double)arr[i] / (double)max) * 100;
        sum += avg[i];
    }

    printf("%lf", sum / subject);
}
