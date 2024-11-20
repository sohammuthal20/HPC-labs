#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void matrix_vector_multiplication(int *matrix, int *vector, int *result, int rows, int cols)
{
#pragma omp parallel for
    for (int i = 0; i < rows; i++)
    {
        result[i] = 0;
        for (int j = 0; j < cols; j++)
        {
            result[i] += matrix[i * cols + j] * vector[j];
        }
    }
}

int main()
{
    int rows = 3;
    int cols = 3;
    int matrix[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // 3x3 matrix
    int vector[3] = {1, 2, 3};                   // 3-dimensional vector
    int result[3];

    matrix_vector_multiplication(matrix, vector, result, rows, cols);

    printf("Result:\n");
    for (int i = 0; i < rows; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}