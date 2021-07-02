/*
TO DO :
  process_args()
  conversion()
  help()

  overflow_detection()
  dynamic_conversion()

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp()

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
void print_buffer(InputData user_data);
void help();


int main(int argc, char const *argv[]) {
  InputData data = process_args(argc, argv);
  print_buffer(data);

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
    } else if(!strcmp(argv[i], "-h")) {
      user_data.input_base = 16;
    } else if(!strcmp(argv[i], "-o")) {
      user_data.input_base = 8;
    } else if(!strcmp(argv[i], "-b")) {
      user_data.input_base = 2;
    } else {
      help();
      exit(1);
    }

    user_data.input_data = process_input(argv[i+1], user_data.input_base);
    return user_data;
  }
}

char* conversion(InputData user_data) {
  // char buffer[32] = {0};
  char* buffer = (char*) malloc(32 * sizeof(char));

  /*
  signed int :
  0000 0000 0000 0111 = 7

  0000 0000 0000  1 111 = -7
  1111 1111 1111  1 000 = one's complement
  1111 1111 1111  1 001 = two's complement (add one)
  */
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
        // transforming decimal number to binary
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

void print_buffer(InputData user_data) {
  int bases[] = {10, 16, 8, 2};
  char* bases_names[] = {"Dec", "Hex", "Oct", "Bin"};

  for (size_t i = 0; i < 4; i++) {
    if (user_data.input_base != bases[i])
      user_data.input_base = bases[i];
    printf("%s: %s\n", bases_names[i], conversion(user_data));
  }

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
