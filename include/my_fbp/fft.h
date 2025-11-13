#ifndef FFT_H
#define FFT_H

#include <complex.h>
#include <stdlib.h>

typedef struct {
  double complex *data;
  int p_value;
} my_vector;

void bit_reversal(my_vector *vector);

#endif // FFT_H
