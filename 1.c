#include <stdio.h>
#include <omp.h>

int main()
{
    int num_threads = 4;

// Parallel region
#pragma omp parallel num_threads(num_threads)
    {
        int thread_id = omp_get_thread_num();
        printf("Hello, World from thread %d!\n", thread_id);
    }

    return 0;
}
