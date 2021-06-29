#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp()

// #define BIN 2
// #define OCT 8
// #define DEC 10
// #define HEX 16

// char *labels[] = {"Dec", "Hex", "Oct", "Bin"};
// int bases[] = {DEC, HEX, OCT, BIN};

typedef enum {
  BIN = 2,
  OCT = 8,
  DEC = 10,
  HEX = 16
} InputBase;

typedef struct {
  long int input_data;
  int sign;
  InputBase input_base;
} InputData;

// overflow detection
long int process_input();
InputData process_args(int argc, char const *argv[]);
char* conversion(InputData user_data);
void help();


int main(int argc, char const *argv[]) {
  InputData data = process_args(argc, argv);
  char* buffer = conversion(data);
  printf("%s\n", buffer);

  return 0;
}


long int process_input(const char* input, int base) {
  long int user_input = strtol(input, (char **)NULL, base);
  return user_input;
}

InputData process_args(int argc, char const *argv[]) {
  InputData user_data;

  for (int i = 1; i < argc; i++) {
    if(strcmp(argv[i], "--help") == 0) {
      help();
      exit(0);
    }

    if(!strcmp(argv[i], "--version") || !strcmp(argv[i], "-v")) {
      printf("gbase version %s\n", "version 1.0");
      exit(0);
    }

    if(!strcmp(argv[i], "--signed") || !strcmp(argv[i], "-s")) {
      user_data.sign = 1;
      continue;
    }

    if(!strcmp(argv[i], "-d")) {
      user_data.input_base = 10;
      user_data.input_data = process_input(argv[i+1], user_data.input_base);
    } else if(!strcmp(argv[i], "-h")) {
      user_data.input_base = 16;
      user_data.input_data = process_input(argv[i+1], user_data.input_base);
    } else if(!strcmp(argv[i], "-o")) {
      user_data.input_base = 8;
      user_data.input_data = process_input(argv[i+1], user_data.input_base);
    } else if(!strcmp(argv[i], "-b")) {
      user_data.input_base = 2;
      user_data.input_data = process_input(argv[i+1], user_data.input_base);
    } else
      help();
  }
  return user_data;
}

char* conversion(InputData user_data) {
  // char buffer[32] = {0};
  char* buffer = (char*) malloc(32 * sizeof(char));

  if(user_data.input_base == 10 && user_data.sign)
    sprintf(buffer, "%ld", user_data.input_data);
  else {
    switch(user_data.input_base) {
      case 10:
        sprintf(buffer, "%lu", user_data.input_data);
        break;
      case 16:
        sprintf(buffer, "%lX", user_data.input_data);
        break;
      case 8:
        sprintf(buffer, "%lo", user_data.input_data);
        break;
      case 2:
      {
        int i;
        int pos;
        // eliminate zeros (junks) in front of int
        for(i = 31; i > 0 && !((1<<i) & user_data.input_data); i--);
        for(pos = 0;i > -1; buffer[pos++] = ((1<<i--) & user_data.input_data) ? '1' : '0');
        buffer[pos] = '\0';
        break;
      }
      default:
        help();
    }
  }
  return buffer;
}

void help() {
  printf("Usage gbase [OPTIONS]\n");
  printf("\nOptions:\n\n");
  printf("    --help                This help\n");
  printf("    --version             Print version number and exit\n\n");
  printf("    -s                    Treat the number as a signed value\n\n");
  printf("    -d <decimal number>   Print this decimal number in all bases\n");
  printf("    -h <hex number>       Print this hexadecimal number in all \
    bases\n");
  printf("    -o <octal number>     Print this octal number in all bases\n");
  printf("    -b <binary number>    Print this binary number in all bases\n");
}
