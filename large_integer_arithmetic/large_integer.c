#include <stdio.h>
#include <stdlib.h>

int* own_atoi(char const argv[]) {
	// find input data's length
	int len_input = 0;
	while (argv[len_input] != '\0') {
		len_input++;
	}

	// printf("size of len_input = %d\n", len_input);
	int* large_interger = malloc(len_input * sizeof(int));

	*large_interger = len_input; // large_interger[0] contain length of array

	for (int i = 1; i < len_input; i++) {
		large_interger[i] = argv[i]; // char to int
		large_interger[i] -= 48; // modulo
	}

	return large_interger;
}



int main(int argc, char const *argv[]) {
	int* nb = own_atoi(argv[1]);

	for (size_t i = 1; i < *(nb+0); i++) {
		printf("%d\n", nb[i]);
	}

  return 0;
}

/*

how to add bits ?



dec -> bin		int[] add_binary(int large_interger[]);
			 hex

hex -> dec
			 bin

bin -> dec
			 hex


*/
