#ifndef CONVERSION
#define CONVERSION

typedef enum {
  BIN = 2,
  OCT = 8,
  DEC = 10,
  HEX = 16
} InputBase;

char* conversion(InputData user_data);

#endif
