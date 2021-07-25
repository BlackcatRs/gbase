#ifndef PROCESSINPUT
#define PROCESSINPUT

typedef struct {
  long int input_data;
  int sign;
  InputBase input_base;
} InputData;

long int process_input();
InputData process_args(int argc, char const *argv[]);

#endif
