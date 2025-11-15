#ifndef FFT_H
#define FFT_H

#include "data.h"

#include <complex.h>
#include <stdlib.h>

/**
 * Perform the RDFT on a projection
 *
 * @param proj The projection to compute
 * @return The RDFT of the projection
 */
fr_projection *real_fft(re_projection *proj);

#endif // FFT_H
