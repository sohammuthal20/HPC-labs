#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

void embed_message(unsigned char *image, const char *message, int image_size);
void extract_message(unsigned char *image, char *message, int image_size);

#endif