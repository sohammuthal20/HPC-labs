#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "steganography.h"
#include "genetic_algorithm.h"
#include "visual_cryptography.h"

#define IMAGE_SIZE 256

int main()
{
    srand(time(NULL));

    unsigned char image[IMAGE_SIZE]; // Example image (array of bytes)
    const char *message = "Hidden Message";

    // Step 1: Steganography - Embed message into image
    embed_message(image, message, IMAGE_SIZE);
    printf("Message Embedded: %s\n", message);

    // Step 2: Steganography - Extract message from image
    char extracted_message[IMAGE_SIZE];
    extract_message(image, extracted_message, IMAGE_SIZE);
    printf("Extracted Message: %s\n", extracted_message);

    // Step 3: Genetic Algorithm - Run genetic algorithm
    genetic_algorithm();

    // Step 4: Visual Cryptography - Generate shares
    unsigned char share1[IMAGE_SIZE], share2[IMAGE_SIZE], reconstructed_image[IMAGE_SIZE];
    generate_shares(image, share1, share2, IMAGE_SIZE);
    combine_shares(share1, share2, reconstructed_image, IMAGE_SIZE);

    printf("Visual Cryptography Process Complete.\n");

    return 0;
}
