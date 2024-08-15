#ifndef __DSP3F_H
#define __DSP3F_H

// #ifdef __cplusplus
// extern "C" {
// #endif // __cplusplus

// common hearders
#include <complex.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Error Type Number */
#define DSP3F_ERROR_CODE_NUM 2
typedef enum {
  // Every thing is ok
  DSP3F_OK = 0,

  // 非法的初始化参数，例如
  // - 设置FFT点数为0
  // - 设置信号带或者滤波器带宽为负数
  DSP3F_ERROR_CONFIG,

  // 算法无法收敛
  DSP3F_ERROR_NO_CONVERGE,

  // 操作所需内存不足
  DSP3F_ERROR_NO_MEMORY

} dsp3f_error_code;

/* DataType：vector */
// - double*：
// - len：数据长度
typedef struct dsp3f_vec_complex {
  double complex *dataArray;
  uint64_t dataLen;

} dsp3f_vec_complex;

/* basic function */
#define DSP3F_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define DSP3F_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define DSP3F_STACK_ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

/* basic: 卷积 */
double *dsp3f_basic_conv(double *h, int lenH, double *x, int lenX,
                         int *convLen);

// #ifdef __cplusplus
//   }
// #endif // __cplusplus

#endif // !__DSP3F_H
