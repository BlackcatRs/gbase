typedef struct {
  long int input_data;
  int sign;
  InputBase input_base;
} InputData;

int* own_atoi(char const argv[]) {
	// find input data's length
	int len_input = 0;
	while (argv[len_input] != '\0') {
		len_input++;
	}

	int* large_interger = (int*) malloc(len_input * sizeof(int));

	*large_interger = len_input; // large_interger[0] contain length of array

	for (int i = 1; i < len_input; i++) {
		large_interger[i] = argv[i]; // char to int
		large_interger[i] -= 48; // modulo
	}

	return large_interger;
}

long int process_input(const char* input, int base) {
  // stop here - what to do when long int (8 bytes) overflow
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
