/*
you have to remove the \n from the string format of the scanf. It should be
scanf("%s",a);

the %s means that the scanf reads the input character till it gets a
delimiter which should be a white space like space or tab or new line(\n)

so the first enter (so input data contain \n because of our enter) is get
as a delimiter for the "%s" and adding the "\n" to the string format "%s\n"
means that the scanf will wait 2 newlines.
equivalent to
  scanf("%s %s", var1, var2);
              or
  scanf("%s\n%s", var1, var2);

the first newline is related to the delimiter of the "%s" and the second
newline is related to the\n of the string format.
*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
  char name[20];
  char surname[20];

  scanf("%s %s", name, surname);
  printf("%s %s\n", name, surname );
  return 0;
}
