#include <stdio.h>
#include <omp.h>

#define N 20
#define CHUNK 4

int main()
{
    int i;
#pragma omp parallel for schedule(static, CHUNK)
    for (i = 0; i < N; i++)
    {
        printf("Thread %d is processing iteration %d\n", omp_get_thread_num(), i);
    }
    return 0;
}