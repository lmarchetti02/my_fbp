#include "my_fbp/fft.h"
#include <complex.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 5
#define P_VALUE 4

my_vector *get_vector(char *file);
void print_vector(my_vector *vector);

int main(void) {
  my_vector *vector = get_vector("data_fft.csv");

  printf("Initial vector:\n");
  print_vector(vector);

  bit_reversal(vector);
  printf("After bit reversal:\n");
  // print_vector(vector);

  free(vector);

  return 0;
}

/*
 * Import vector from .csv file
 */
my_vector *get_vector(char *file) {
  FILE *p_file = fopen("data_fft.csv", "r");
  if (p_file == NULL) {
    fprintf(stderr, "Impossible to open file");
    exit(1);
  }

  double complex *data = malloc(1024 * sizeof(double complex));

  int i = 0;
  char buffer[100];
  while (fgets(buffer, sizeof(buffer), p_file)) {
    // get real
    char *token = strtok(buffer, ",");
    double real = atof(token);
    // get imaginary
    token = strtok(NULL, ",");
    double imaginary = atof(token);

    data[i] = real + imaginary * I;
    i++;
  }

  fclose(p_file);

  my_vector *vector = malloc(sizeof(my_vector));
  vector->data = data;
  vector->p_value = 10;

  return vector;
}

/*
 * Print complex vector
 */
void print_vector(my_vector *vector) {

  int size = 2 << (vector->p_value - 1);
  for (int i = 0; i < size; i++) {
    printf("%i: %.3lf + %.3lfi\n", i, creal(vector->data[i]),
           cimag(vector->data[i]));
  }
}
