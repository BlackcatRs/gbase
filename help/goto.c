/*
 there are a few situations where gotos may find a place. The most common
 is to abandon processing in some deeply nested structure, such as breaking
 out of two or more loops at once. The break statement cannot be used
 directly since it only exits from the innermost loop. Thus:
     for ( ... )
              for ( ... ) {
                  ...
                  if (disaster)
                      goto error;
              }
          ...
      error:
          // clean up the mess


*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char cmd[20];
  while (1) {
    while (1) {
      printf("enter break to quit : ");
      scanf("%s", cmd);
      if (!strcmp(cmd, "break")) {
        break;
      }
    }
  }
  return 0;
}
