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

// prompt the user demographic information including name, age, class year, and any three
// other data times you wish. Structure the program as a call-and-response program such that each data item
//is a single question with a single answer.
//When all data has been obtained, display the data on the console. Each data item must be on a separate line,