#include "my_fbp/fft.h"

#include <fftw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

fr_projection *real_fft(re_projection *proj)
{

  fftw_plan plan;
  size_t out_size = proj->size / 2 + 1;
  fftw_complex *out_data = malloc(sizeof(fftw_complex) * out_size);

  plan = fftw_plan_dft_r2c_1d(proj->size, proj->data, out_data, FFTW_ESTIMATE);
  fftw_execute(plan);

  fftw_destroy_plan(plan);

  fr_projection *out = malloc(sizeof(fr_projection));
  out->data = out_data;
  out->size = out_size;

  return out;
}
