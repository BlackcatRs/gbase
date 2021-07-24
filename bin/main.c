#include <stdio.h>
#include "bin.h"

int main(int argc, char const *argv[]) {
  char binary[6] = {'1', '1', '1', '0', '1'};
  incremnt_bit(binary);

  for (int i = 0; i < 6; i++) {
    printf("%c", binary[i]);
    printf("\n");
  }

  return 0;
}
