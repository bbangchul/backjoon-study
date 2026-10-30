#include <iostream>
using namespace std;

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (A[j - 1] > A[j])
            {
                Swap(&A[j - 1], &A[j]);
            }
        }
    }
}

int main()
{
    int A[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int n = 8;

    BubbleSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}