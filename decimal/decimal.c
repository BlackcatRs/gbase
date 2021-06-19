#include "decimal.h"

// decimal to binary (bits in buf are in lsb order)
void decimal_binary(int *buf, int nb) {
  int index = 0;

  while (1) {
    buf[index] = nb%2;
    nb = nb/2;
    index++;

    // first bit starts always with 1
    if (nb == 1) {
      buf[index] = 1;
      index++; // not necessaire
      break;
    }
  }

}
