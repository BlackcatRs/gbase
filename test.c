#include <stdio.h>

int main(int argc, char const *argv[]) {
  int answer = 2;
  switch (answer) {
    case 1:
      printf("case 1\n");
      break;
    case 2:{
      int age = 23;
      printf("age is %d\n", age);
      break;}
    default:
      printf("default\n");

  }
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
