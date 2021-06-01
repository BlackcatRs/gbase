/*
TO DO :
  nb_power_pow() 2nd parm name need to change to x
  buf_binary to binary_buf (for hex hex_buf)
  increase buf_binary space for \0
*/

#include <stdio.h>

// print buf
void print_buf(int *buf, int buf_size) {
  // print buf in reverse order
  for (int i = buf_size-1; i > 0; i--) {
    printf("%d\n", buf[i]);
  }
}


void initialize_buff(int *buf, int buffer_size) {
  for (size_t i = 0; i < buffer_size; i++) {
    *(buf + i) = 0;
  }
}


int main(int argc, char const *argv[]) {
  int buf[5];
  initialize_buff(buf, 5);

  // for (int i = 4; i >= 0; i--) {
  //   printf("index %d = %d\n", i, buf[i]);
  // }

  print_buf(buf, 5);
  return 0;
}
