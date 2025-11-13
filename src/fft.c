#include "my_fbp/fft.h"

/**
 * Perform bit reversal sorting in place on a complex vector.
 *
 * @param[in,out] vector The vector to sort.
 * @param[in] p The exponent 2^p
 * @return void
 */
void bit_reversal(my_vector *vector) {
  int size = 2 << vector->p_value;

  // run through indices
  for (int n = 0; n < size; n++) {
    int j = 0;
    int m = n;
    // perform bit reversal
    for (int i = 0; i < vector->p_value; i++) {
      j = 2 * j + m % 2;
      m = m / 2;
    }
    // swap if reverse > original
    if (j > n) {
      double complex h = vector->data[j];
      vector->data[j] = vector->data[n];
      vector->data[n] = h;
    }
  }
}
