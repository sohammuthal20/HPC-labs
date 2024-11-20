#include <stdio.h>
#include <omp.h>
#include <string.h>

#define BLOCK_SIZE 16
#define DATA_SIZE 64

// Dummy encryption function (XOR for simplicity)
void encrypt_block(unsigned char *input, unsigned char *output, unsigned char *key)
{
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        output[i] = input[i] ^ key[i];
    }
}

void parallel_encrypt_openmp(unsigned char *data, unsigned char *encrypted, unsigned char *key)
{
    int num_blocks = DATA_SIZE / BLOCK_SIZE;

// Parallel encryption using OpenMP
#pragma omp parallel for
    for (int i = 0; i < num_blocks; i++)
    {
        encrypt_block(&data[i * BLOCK_SIZE], &encrypted[i * BLOCK_SIZE], key);
    }
}

int main()
{
    unsigned char data[DATA_SIZE] = "Hello, this is a test for parallel AES encryption!";
    unsigned char encrypted[DATA_SIZE];
    unsigned char key[BLOCK_SIZE] = "mysecretpassword";

    printf("Original Data: %s\n", data);

    // Perform parallel encryption
    parallel_encrypt_openmp(data, encrypted, key);

    // Print encrypted data in hex format
    printf("Encrypted Data:\n");
    for (int i = 0; i < DATA_SIZE; i++)
    {
        printf("%02X ", encrypted[i]);
    }
    printf("\n");

    return 0;
}
