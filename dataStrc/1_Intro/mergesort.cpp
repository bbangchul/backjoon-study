#include <iostream>
using namespace std;

const int NUM_OF_KEYS = 100;

void Merge(int A[], int low, int mid, int high)
{
    int B[NUM_OF_KEYS];

    int leftPtr = low;
    int rightPtr = mid + 1;
    int bufPtr = low;

    while (leftPtr <= mid && rightPtr <= high)
    {
        if (A[leftPtr] <= A[rightPtr])
            B[bufPtr++] = A[leftPtr++];
        else
            B[bufPtr++] = A[rightPtr++];
    }

    if (leftPtr > mid)
    {
        for (int i = rightPtr; i <= high; i++)
            B[bufPtr++] = A[i];
    }
    else
    {
        for (int i = leftPtr; i <= mid; i++)
            B[bufPtr++] = A[i];
    }

    for (int i = low; i <= high; i++)
        A[i] = B[i];
}

void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int n = 8;

    MergeSort(A, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}