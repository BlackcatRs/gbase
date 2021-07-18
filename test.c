/*
___own atoi function___
"67" est de type de char*
parcourir la lettre par lettre
recupere la coresspondance en dec a l'aide de l"ascii
multiplier par 10

et puis 2eme lettre

la difference entre int et char est la taille
donc une chaine de caracteres est un ensemeble de chars
*/


/*
to negate a number, you need to transform the number to 2's complement
so you need to know adding and substructig two binaries
*/



#include <stdio.h>

int main() {
  // char* tamil = "\u0BA4";
  // long int max_value = (1,844674407)*(10*19);
  // long int max_value = (9,223372037)*(10*18);
  int i = 5;
  char buffer[i];

  for (size_t i = 0; i < 5; i++) {
    buffer[i] = 'v';
  }

  for (size_t i = 0; i < 5; i++) {
    printf("%c\n", buffer[i]);
  }

}


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
