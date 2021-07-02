/*
"67" est de type de char*
parcourir la lettre par lettre
recupere la coresspondance en dec a l'aide de l"ascii
multiplier par 10

et puis 2eme lettre

la difference entre int et char est la taille
donc une chaine de caracteres est un ensemeble de chars


43 = +
48 = 0

in char* format
  00101011 00110000

in int format
11056



*/

#include <stdio.h>

int main(int argc, char const *argv[]) {
  int nb = 128516; //emoji
  printf("%ls\n", &nb);
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
