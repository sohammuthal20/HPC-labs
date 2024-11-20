#include <stdio.h>
#include <omp.h>

int main()
{
    int i;
    int n = 10;
    int arr[n];

    for (i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
#pragma omp parallel for private(i)
    for (i = 0; i < n; i++)
    {
        int square = arr[i] * arr[i];
        printf("Thread %d: The square of %d is %d\n", omp_get_thread_num(), arr[i], square);
    }
    return 0;
}
