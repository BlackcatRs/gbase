#include "gbase.h"
#include <stdio.h>


// print buf
void print_buf(int *buf, int buf_size) {
  // print buf in reverse order
  for (int i = buf_size-1; i >= 0; i--) {
    printf("%d", buf[i]);
  }

  printf("\n");
}

// "nb" power to "pow"
int nb_power_pow(int nb, int pow) {
  // x^0 = 1
  if (pow == 0) {
    return 1;
  }

  // x^1 = x
  int result = nb; //2
  for (size_t i = 1; i < pow; i++) {
    result = result*nb;
  }

  return result;
}

void initialize_buffer(int buffer[], size_t buf_size) {
  for (size_t i = 0; i < buf_size; i++) {
    buffer[i] = 0;
  }
}


// determine buf size
int buf_size(int nb) {
  int nb_bits = 1;
  /*
  nb_power_pow(2, power) values possible with "power" bits
  ex :
    power = 2
    nb_power_pow(2, power) = 4 values possible
                          or
    2^2 = 4 values possible
    2 bits can represent 0-3 in decimal.
    _____________________
    | Binary  | Decimal |
    |   00    |   0     |
    |   01    |   1     |
    |   10    |   1     |
    |   11    |   3     |
     -------------------

  */
  while (nb > (nb_power_pow(2, nb_bits)-1)) {
    nb_bits++;
  }

  return nb_bits+1;
}
