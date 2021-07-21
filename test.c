/*
to negate a number, you need to transform the number to 2's complement
so you need to know adding and substructig two binaries
*/



#include <stdio.h>

int main(int argc, char const *argv[]) {
  const char *user_input = argv[1];
  int i = 0;
  // printf("%s\n", user_input);


  while (user_input[i] != '\0') {
    printf("%c", user_input[i]);
    i++;
  }
  return 0;
}

// int main() {
//   // char* tamil = "\u0BA4";
//   // long int max_value = (1,844674407)*(10*19);
//   // long int max_value = (9,223372037)*(10*18);
//   int i = 5;
//   char buffer[i];
//
//   for (size_t i = 0; i < 5; i++) {
//     buffer[i] = 'v';
//   }
//
//   for (size_t i = 0; i < 5; i++) {
//     printf("%c\n", buffer[i]);
//   }
//
// }


/*
what to do when char overflow
  create a int array
  define multiplication methode
         division
         adding
         substraction


TO DO:
        binary substruction
                division




let me explain :
  5434
x    2
 10838

p[] = {10, 8, 3, 8}




*/
