#include <stdio.h>
#include <omp.h>

void operation();

int main()
{
#pragma omp parallel num_threads(10)
    operation();
    return 0;
}

void operation()
{
    int th_no;
    th_no = omp_get_thread_num();
    printf("Hello from %d \n", th_no);
}