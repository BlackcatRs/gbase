#include <stdio.h>
#include "process_input/process_input.h"
#include "conversion/conversion.h"
#include "display/display.h"

// #include <stdlib.h>
// #include <string.h> //strcmp()

int main(int argc, char const *argv[]) {
  InputData data = process_args(argc, argv);
  print_buffer(data);

  return 0;
}
