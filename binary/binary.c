#include "binary.h"

int binary_decimal(int *buf, int buf_size) {
  int decimal = 0;
  for (size_t i = 0; i < buf_size; i++) {
    if (buf[i]) {
      // printf("index = %d\n", i);
      decimal += nb_power_pow(2, i);
      // printf("decimal value = %d\n", nb_power_pow(2, i));
    }
  }

  return decimal;
}
