/*
what consume resources
	- loop
	- malloc et realloc
*/

#include <stdio.h>


// TO DO : malloc dynamic
// TO DO : return struct (buff + size)
int* own_atoi(char const argv[]) {
	static int large_interger[31];
	int i = 0;

	while (argv[i] != '\0') {
		large_interger[i] = argv[i]; // char to int
		large_interger[i] -= 48; // modulo
		i++;
	}

	return large_interger;
}

int main(int argc, char const *argv[]) {
	int *nb = own_atoi(argv[1]);

	for (size_t i = 0; i < 6; i++) {
		printf("%d\n", nb[i]);
	}

  return 0;
}

























//
