#include <stdio.h>
/*
TO DO :
  nb_power_pow() 2nd parm name need to change to x
  buf_binary to binary_buf (for hex hex_buf)
  increase buf_binary space for \0
*/

/*
  Binary number is a number expressed in the base-2 numeral system or binary
  numeral system, a method of mathematical expression which uses only two
  symbols: typically "0" (zero) and "1" (one).

  base 16
    one number in base-16 can reprensent one of 16 symbols

  decimal to binary
  divided into 4 bits
  and do the conresponding with hex table


  hex to decimal
  every number to power 16

*/



int main(int argc, char const *argv[]) {
  char nom[5];
  char prenom[5];

  scanf("%s %s", nom, prenom);
  printf("%s, %s\n", nom, prenom);
  return 0;
}


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
