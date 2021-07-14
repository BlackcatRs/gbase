/*
what consume resources
	- loop
	- malloc et realloc
*/

#include <stdio.h>
#define BASE 10

// 12343
int* own_atoi(char const argv[]) {
	int large_interger[31];
	int i = 0;

	while (argv[i] != '\0') {
		large_interger[i] = argv[i++];
	}
	large_interger[i] = '\0';

}

int main(int argc, char const *argv[]) {
	int* nb = own_atoi(argv[1]);


	//
	// for (size_t i = 0; i < 30; i++) {
	// 	printf("%ld = %d\n", i, nb[i]);
	// }

  return 0;
}
