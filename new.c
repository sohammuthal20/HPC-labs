#include <stdio.h>
#include <omp.h>

int main()
{
    // Array of family member names
    const char *family_names[] = {"John", "Jane", "Alice", "Bob"};
    int num_family_members = 4;

    // Set the number of threads to the number of family members
    omp_set_num_threads(num_family_members);

// Parallel region where each thread prints a family member's name
#pragma omp parallel
    {
        // Get the thread ID
        int thread_id = omp_get_thread_num();

        // Print the name and the thread ID
        printf("Family Member: %s, Thread ID: %d\n", family_names[thread_id], thread_id);
    }

    return 0;
}
