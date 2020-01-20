 /** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  File name     :  SayHello.c
 *  Purpose       :  Provides a simple method to retrieve and print out user given data. 
 *  Author        :  Talia Bahar, Maya Pegler-Gordon, Veronica Backer Peral 
 *  Date          :  2020-01-20
 *  Description   :  This program prompts the user for their name using the printf() and gets() functions
 *                   and then prints "Hello" followed by the user's entered name.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[] ) {
  char input[25];
  printf( "Enter a name: ");
  gets(input);
  printf ( "\n\n Hello, %s!\n\n", input);
  exit(0);
}
