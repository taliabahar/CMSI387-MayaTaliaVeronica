#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[] ) {
	char input[25];
	printf( "Enter a name: ");
	gets(input);
	printf ( "\n\n Hello, %s!\n\n", input);
	exit(0);
}