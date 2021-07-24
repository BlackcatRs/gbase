/*
Binary addition
0+0 = 0
0+1 = 1
1+0 = 1
1+1 = 0 (1 carries out)
*/

#include <stdio.h> // for printf

// increment one bit
void incremnt_bit(char buf[]) {
  int i = 0;
  char carry = '0';

  while (buf[i] != '\0') {
    if (buf[i] == '1') {
      buf[i] = '0';
      carry = '1';
      printf("in if\n");
    }
    else {
      printf("in else\n");
      buf[i] = '1';
      carry = '0';
      break;
    }
    i++;
  }

  // TO DO: prevent overflow
  if (carry == '1') printf ("overflow in addition!\n");
}
