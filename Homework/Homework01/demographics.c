/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  File name     :  demographics.c
 *  Purpose       :  Provides a simple method to retrieve and print out user given data. 
 *  Author        :  Talia Bahar, Maya Pegler-Gordon, Veronica Backer Peral 
 *  Date          :  2020-02-4
 *  Description   :  This program prompts the user for their name, age, class year, major, minor, 
 *                   and fun fact one at a time using the printf() and gets() functions and then 
 *                   prints the results on a new line.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char name[25];
    char age[3];
    char classYear[10];
    char major[25];
    char minor[25];
    char funFact[25];
    printf("What is your name?: ");
    gets(name);
    printf("How old are you?: ");
    gets(age);
    printf("What year are you?: ");
    gets(classYear);
    printf("What is your major?: ");
    gets(major);
    printf("What is your minor?: ");
    gets(minor);
    printf("What is a fun fact about you?: ");
    gets(funFact);

    printf("\n\n Name: %s\n Age: %s\n Class Year: %s\n Major: %s\n Minor: %s\n Fun Fact: %s\n", name, age, classYear, major, minor, funFact);
    exit(0);
}