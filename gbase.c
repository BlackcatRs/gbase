#include <stdio.h>

void initialize_buffer(int buffer[], size_t buf_size) {
  for (size_t i = 0; i < buf_size; i++) {
    buffer[i] = 0;
  }
}

// decimal to binary
void decimal_binary(int *buf, int nb) {
  int index = 0;

  while (1) {
    buf[index] = nb%2;
    nb = nb/2;
    index++;

    // first bit starts always with 1
    if (nb == 1) {
      buf[index] = 1;
      index++;
      break;
    }
  }

}

// determine buf size
int buf_size(int nb) {
  
}


int main(int argc, char const *argv[]) {
  int decimal = 30;
  int result = decimal;
  /*
  buffer size need to be large enough to hold all bits,
  solution 1
    use decimal number to determine buffer size
    2^1 = 2 if decimal < 2 use this
    2^2 = 4 if decimal < 4 use this

  solution 2
    buffer resize automatically (there must be if condition check space in buf)
  */

  int binary[50];

  initialize_buffer(binary, 50);
  decimal_binary(binary, decimal);


  for (int i = 50; i >= 0; i--) {
    printf("%d\n", binary[i]);
  }

  return 0;
}


/*
26/2 = 13
26-(13*2) = 0

13/2 = 6
13-(6*2) = 1

6/2 = 3
6-(3*2) = 0

3/2 = 1
3-(1*2) = 1

1



*/
