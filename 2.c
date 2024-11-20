#include <stdio.h>
#include <omp.h>

int main()
{
// Parallel region
#pragma omp parallel num_threads(4)
    {
        // Print the thread number for each thread
        printf("Soham Muthal ---> Thread %d!\n", omp_get_thread_num());
    }

    return 0;
}
