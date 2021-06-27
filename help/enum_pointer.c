#include <stdio.h>
#include <stdlib.h>

typedef enum {
  monday,
  tue,
  wed
} Days;


int main(int argc, char const *argv[]) {
  Days *current_date = (Days *) malloc(sizeof(Days));
  *current_date = wed;

  printf("%d\n", *current_date);
  return 0;
}
