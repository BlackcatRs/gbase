#ifndef DEF_PROCESSINPUT
#define DEF_PROCESSINPUT


typedef enum {
  BIN = 2,
  OCT = 8,
  DEC = 10,
  HEX = 16
} InputBase;

// user data after input process
typedef struct {
  long int input_data;
  int sign;
  InputBase input_base;
} InputData;

typedef struct {
  int* len;
  int* array;
} LargeInterger;


LargeInterger* own_atoi(char const argv[]);
long int process_input(const char* input, int base);
InputData process_args(int argc, char const *argv[]);

#endif
