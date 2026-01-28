#include <stdio.h>

int main(void)
{

    int students_list[30] = {0};
    int min = 0, max = 0, temp = 0;
    int first_found = 0;

    for (int i = 0; i < 30; i++)
    {
        students_list[i] = i + 1;
    }

    for (int i = 1; i <= 28; i++)
    {
        scanf("%d", &temp);
        students_list[temp - 1] = 0;
    }

    for (int i = 0; i < 30; i++)
    {
        if (students_list[i] != 0)
        {
            if (!first_found)
            {
                min = max = students_list[i];
                first_found = 1;
            }
            else
            {
                if (students_list[i] < min)
                {
                    min = students_list[i];
                }
                if (students_list[i] > max)
                {
                    max = students_list[i];
                }
            }
        }
    }
    printf("%d\n%d", min, max);
}