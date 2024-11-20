#include <stdio.h>
#include <omp.h>

#define N 10

void print_twos()
{
    for (int i = 0; i < N; i++)
    {
        printf("2");
    }
    printf("\n");
}

void print_fours()
{
    for (int i = 0; i < N; i++)
    {
        printf("4");
    }
    printf("\n");
}

int main()
{
    // Set the number of threads to 2
    omp_set_num_threads(2);

#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        if (thread_id == 0)
        {
            print_twos(); // Thread 0 prints the series of 2
        }
        else if (thread_id == 1)
        {
            print_fours(); // Thread 1 prints the series of 4
        }
    }

    return 0;
}
