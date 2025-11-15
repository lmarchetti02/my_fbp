#ifndef DATA_H
#define DATA_H

#include <fftw3.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>

/**
 * Structure to store the real projections
 */
typedef struct re_projection {
  double_t *data;
  size_t size;
} re_projection;

/**
 * Structure to store the DFT of the projections
 */
typedef struct fr_projection {
  fftw_complex *data;
  size_t size;
} fr_projection;

#endif // DATA_H
