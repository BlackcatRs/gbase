#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  int input = strtol(argv[1], (char **)NULL, 2);
  printf("%s\n", input);
  return 0;
}


/*
// #include <stdio.h>
//
// int main() {
//   char* smily = "\uD83DDE36";
//   char* tamil = "\u0BA4";
//   char* latin = "a";
//   printf("%s\n", smily);
//   // printf("%ld", sizeof(tamil));
// }


/*
TO DO :
  process_args()
  conversion()
  help()

  overflow_detection()
  dynamic_conversion()

*/
