#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp()
#include <stddef.h> // for NULL
#include "process_input.h"

// char to int[]
LargeInterger* own_atoi(char const user_input[]) {
  // NEED : free this malloc
  LargeInterger* large_interger = malloc(sizeof(LargeInterger));

	// find input data's length
	int len_input = 0;
	while (user_input[len_input] != '\0') {
		len_input++;
	}

  // NEED : free this malloc
	large_interger->array = malloc(len_input * sizeof(int));
  large_interger->len = malloc(sizeof(int)); // TODO: need to be dynamic

  *large_interger->len = len_input;

	for (int i = 0; i < len_input; i++) {
		large_interger->array[i] = user_input[i]; // char to int
		large_interger->array[i] -= 48; // modulo
	}
  // printf("i am here\n");


	return large_interger;
}

long int process_input(const char* input, int base) {
  // stop here - what to do when long int (8 bytes) overflow
  long int user_input = strtol(input, (char **)NULL, base);
  return user_input;
}

// process user's input
InputData process_args(int argc, char const *argv[]) {
  InputData user_data;

  for (int i = 1; i < argc; i++) {
    if(strcmp(argv[i], "--help") == 0) {
      // help();
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
      // help();
      exit(1);
    }

    user_data.input_data = process_input(argv[i+1], user_data.input_base);
    return user_data;
  }
}
