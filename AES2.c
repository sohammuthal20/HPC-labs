#include <stdio.h>
#include <cuda_runtime.h>

#define BLOCK_SIZE 16
#define DATA_SIZE 64

__device__ void encrypt_block_device(unsigned char *input, unsigned char *output, unsigned char *key)
{
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        output[i] = input[i] ^ key[i]; // XOR-based encryption
    }
}

__global__ void parallel_encrypt_cuda(unsigned char *data, unsigned char *encrypted, unsigned char *key)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < DATA_SIZE / BLOCK_SIZE)
    {
        encrypt_block_device(&data[idx * BLOCK_SIZE], &encrypted[idx * BLOCK_SIZE], key);
    }
}

int main()
{
    unsigned char data[DATA_SIZE] = "Hello, CUDA parallel AES encryption example!";
    unsigned char encrypted[DATA_SIZE];
    unsigned char key[BLOCK_SIZE] = "simplesecretkey";

    unsigned char *d_data, *d_encrypted, *d_key;
    cudaMalloc(&d_data, DATA_SIZE);
    cudaMalloc(&d_encrypted, DATA_SIZE);
    cudaMalloc(&d_key, BLOCK_SIZE);

    cudaMemcpy(d_data, data, DATA_SIZE, cudaMemcpyHostToDevice);
    cudaMemcpy(d_key, key, BLOCK_SIZE, cudaMemcpyHostToDevice);

    parallel_encrypt_cuda<<<DATA_SIZE / BLOCK_SIZE, 1>>>(d_data, d_encrypted, d_key);

    cudaMemcpy(encrypted, d_encrypted, DATA_SIZE, cudaMemcpyDeviceToHost);

    printf("Original Data: %s\n", data);

    printf("Encrypted Data:\n");
    for (int i = 0; i < DATA_SIZE; i++)
    {
        printf("%02X ", encrypted[i]);
    }
    printf("\n");

    cudaFree(d_data);
    cudaFree(d_encrypted);
    cudaFree(d_key);

    return 0;
}
