#include <stdio.h>
#include <omp.h>
int main()
{
    omp_set_num_threads(4);

    int val = 1234;
    printf("Initial value of val: %d\n", val);

#pragma omp parallel firstprivate(val)
    {
        printf("Thread %d: Current value of val = %d\n", omp_get_thread_num(), val);
        val += 1;
        printf("Thread %d: Updated value of val = %d\n", omp_get_thread_num(), val);
    }

    printf("Final value of val after parallel region: %d\n", val);
    return 0;
}