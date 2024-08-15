#include "dsp3f.h"
#include <stdint.h>
#include <string.h>
double *dsp3f_basic_conv(double *h, int lenH, double *x, int lenX,
                         int *convLen) {
  /* 卷积长度 */
  *convLen = lenH + lenX - 1;

  /* 为卷积结果分配空间，并进行初始化 */
  double *conv_result = calloc(*convLen, sizeof(double));

  /* 开始卷积 */
  int i, j, h_start, x_start, x_end;

  for (i = 0; i < *convLen; i++) {
    x_start = DSP3F_MAX(0, i - lenH + 1);
    x_end = DSP3F_MIN(i + 1, lenX);
    h_start = DSP3F_MIN(i, lenH - 1);

    for (j = x_start; j < x_end; j++) {
      conv_result[i] += h[h_start--] * x[j];
    }
  }

  return conv_result;
}
