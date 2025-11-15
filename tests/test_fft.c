#include "my_fbp/data.h"
#include "my_fbp/fft.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define X 6000
#define Y 500

int main(void)
{

  double in[X];
  for (int i = 0; i < X; i++)
    in[i] = sin((double)i / 100);

  re_projection *proj = malloc(sizeof(re_projection));
  proj->data = in;
  proj->size = X;

  fr_projection *out = real_fft(proj);

  return 0;
}
