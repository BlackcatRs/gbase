#include <stdio.h>

const char* user_input(const char *argv[]) {
  const char* username = argv[1];
  return username;
}


int main(int argc, char const *argv[]) {
  const char* name = user_input(argv);
  printf("%s\n", name);
  return 0;
}
