#include <stdio.h>
#include <omp.h>
int main()
{
#pragma omp parellel
    {
        printf("hello world");
    }
    return 0;
}