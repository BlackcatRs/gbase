#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  int n = -8;
  while (n > 1) {
    if (n & 1)
        printf("1");
    else
        printf("0");

    n >>= 1;
}
printf("\n");


  return 0;
}


/*
0000 0000 0000 0111 = 7

0000 0000 0000  1 111 = -7
1111 1111 1111  1 000 = one's complement
1111 1111 1111  1 001 = two's complement (add one)
*/



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
