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





// Decimal to Hexadecimal in C
// ----codescracker.com----

#include<stdio.h>
// #include<conio.h>
int main()
{
  int decnum, rem, i=0;
  char hexnum[50];
  printf("Enter any decimal number: ");
  scanf("%d", &decnum);
  while(decnum!=0)
  {
      rem = decnum%16;
      if(rem<10)
          rem = rem+48;
      else
          rem = rem+55;
      hexnum[i] = rem;
      i++;
      decnum = decnum/16;
  }
  printf("\nEquivalent Value in Hexadecimal = ");
  for(i=i-1; i>=0; i--)
      printf("%c", hexnum[i]);
  // getch();
  return 0;
}
