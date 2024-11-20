#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

void crossover(unsigned char *parent1, unsigned char *parent2, unsigned char *offspring, int image_size);
void mutate(unsigned char *image, int image_size);
void genetic_algorithm();

#endif
