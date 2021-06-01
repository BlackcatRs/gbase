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

int main(int argc, char const *argv[]) {
  int decimal = 26; // user input
  const int BUFFER_SIZE = buf_size(decimal);

  // int buf_binary[BUFFER_SIZE];
  int buf[6] = {0, 1, 1, 1, 1};

  // initialize_buffer(buf_binary, BUFFER_SIZE);
  // decimal_binary(buf_binary, decimal);
  // print_buf(buf_binary, BUFFER_SIZE);

  printf("%d\n", binary_decimal(buf, 5));
  // binary_decimal(buf_binary, BUFFER_SIZE);

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
/*
buffer size need to be large enough to hold all bits,
solution 1
  use decimal number to determine buffer size
  2^1 = 2 if decimal < 2 use this
  2^2 = 4 if decimal < 4 use this

solution 2
  buffer resize automatically (there must be if condition check space in buf)
*/
