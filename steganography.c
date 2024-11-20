#include <stdio.h>
#include <stdlib.h>
#include "steganography.h"

void embed_message(unsigned char *image, const char *message, int image_size)
{
    int i = 0;
    int j = 0;
    while (message[j] != '\0' && i < image_size)
    {
        for (int k = 7; k >= 0; k--)
        {
            image[i] = (image[i] & 0xFE) | ((message[j] >> k) & 0x01);
            i++;
        }
        j++;
    }
}

void extract_message(unsigned char *image, char *message, int image_size)
{
    int i = 0;
    int j = 0;
    while (i < image_size)
    {
        char ch = 0;
        for (int k = 7; k >= 0; k--)
        {
            ch |= ((image[i] & 0x01) << k);
            i++;
        }
        message[j++] = ch;
    }
    message[j] = '\0'; // Null-terminate the message
}
