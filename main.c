#include <stdio.h>
#include <stdlib.h>

#define BIN 2
#define OCT 8
#define DEC 10
#define HEX 16

// char *labels[] = {"Dec", "Hex", "Oct", "Bin"};
// int bases[] = {DEC, HEX, OCT, BIN};

typedef enum {
  BIN 2,
  OCT 8,
  DEC 10,
  HEX 16
} InputBase;

typedef struct {
  long int input_data;
  int signed;
  InputBase input_base;
} StatementType;


void process_args(int argc, char const *argv[]);
void conversion(int base);
void help();


int main(int argc, char const *argv[]) {
  long int accumulator = strtol(argv[i+1], (char **)NULL, type);
  char buffer[33];

  return 0;
}


void process_args(int argc, char const *argv[]) {
  // stop here - need to replace this variable with StatementType
  int input_base = 0;

  for (int i = 1; i < argc; i++) {
    if(strcmp(argv[i], "--help") == 0) {
      help();
      exit(0);
    }

    if(!strcmp(argv[i], "--version") || !strcmp(argv[i], "-v")) {
      printf("gbase version %s\n", version);
      exit(0);
    }

    if(!strcmp(argv[i], "--signed") || !strcmp(argv[i], "-s")) {
      val_is_signed = SIGNED;
      continue;
    }

    if(!strcmp(argv[i], "-d"))
      conversion(DEC);
    else if(!strcmp(argv[i], "-h"))
      conversion(HEX);
    else if(!strcmp(argv[i], "-o"))
      conversion(OCT);
    else if(!strcmp(argv[i], "-b"))
      conversion(BIN);
    else
      help();
  }

}

void conversion(int base) {
  if(base == DEC && val_is_signed)
    sprintf(buffer, "%ld", accumulator);
  else {
    switch(base) {
    case DEC:
      sprintf(buffer, "%lu", accumulator);
      break;
    case HEX:
      sprintf(buffer, "%lX", accumulator);
      break;
    case OCT:
      sprintf(buffer, "%lo", accumulator);
      break;
    case BIN:
      // eliminate zeros (junks) in front of int
      for(i = 31; i > 0 && !((1<<i) & accumulator); i--);
      for(pos = 0;i > -1; buffer[pos++] = ((1<<i--) & accumulator) ? '1' : '0');
      buffer[pos] = '\0';
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
