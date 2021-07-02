/*
When fgets reads input from the user, it will read up to size-1 characters
and then place the null terminator after the last character it read.
fgets will read input until it either has no more room to store the data or
until the user hits enter. Notice that fgets may fill up the entire space
allocated for str, but it will never return a non-null terminated string to you.
*/

#include <stdio.h>  //the standard library file
#include <stdlib.h> //library file useful for dynamic allocation of memory
#include <string.h> //library file with functions useful to handle strings

//the function
char* scan(char *string)
{
    int c; //as getchar() returns `int`
    string = malloc(sizeof(char)); //allocating memory

    string[0]='\0';

    for(int i=0; i<100 && (c=getchar())!='\n' && c != EOF ; i++)
    {
        string = realloc(string, (i+2)*sizeof(char)); //reallocating memory
        string[i] = (char) c; //type casting `int` to `char`
        string[i+1] = '\0'; //inserting null character at the end
    }

    return string;
}

int main(void)
{
    char *buf; //pointer to hold base address of string

    while( strcmp((buf=scan(buf)),"end") )
    {
        printf("you entered : %s\n",buf);
        printf("size        : %lu\n",strlen(buf));
        printf("\n-------------------\n");

        free(buf);
    }

    free(buf); //freeing `buf` for last input i.e, `end`

}
