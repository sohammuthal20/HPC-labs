#include <stdio.h>
#include <omp.h>

#define BLOCK_SIZE 16
#define DATA_SIZE 64

void encrypt_block(unsigned char *input, unsigned char *output, unsigned char *key)
{
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        output[i] = input[i] ^ key[i]; // XOR-based encryption
    }
}

void parallel_encrypt_openmp(unsigned char *data, unsigned char *encrypted, unsigned char *key)
{
#pragma omp parallel for
    for (int i = 0; i < DATA_SIZE / BLOCK_SIZE; i++)
    {
        encrypt_block(&data[i * BLOCK_SIZE], &encrypted[i * BLOCK_SIZE], key);
    }
}

int main()
{
    unsigned char data[DATA_SIZE] = "Hello, OpenMP parallel AES encryption example!";
    unsigned char encrypted[DATA_SIZE];
    unsigned char key[BLOCK_SIZE] = "simplesecretkey";

    printf("Original Data: %s\n", data);

    parallel_encrypt_openmp(data, encrypted, key);

    printf("Encrypted Data:\n");
    for (int i = 0; i < DATA_SIZE; i++)
    {
        printf("%02X ", encrypted[i]);
    }
    printf("\n");

    return 0;
}
