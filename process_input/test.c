#include <stdio.h>
#include "process_input.h"
#include <stdlib.h> //for malloc

int main(int argc, char const *argv[]) {
  own_atoi(argv[1]);
  //
  // typedef struct {
  //   int* a;
  //   int* array;
  // } test;
  //
  // test* large_interger = malloc(sizeof(test));
  // large_interger->a = 34;
  // large_interger->array = malloc(5 * sizeof(int));
  //
  // int cmt = 2;
  // for (int i = 0; i < 5; i++) {
	// 	large_interger->array[i] = (cmt *= 2); // char to int
  //   *large_interger->array = 1+cmt;
	// }
  //
  // for (int i = 0; i < 5; i++) {
  //   printf("%d\n", large_interger->array[i]);
  //   // printf("%d\n", *(large_interger->a));
  // }
  // printf("%d\n", *(large_interger->a));

  return 0;
}
