#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END_CHAR -9999;

// Count the number of elements in the structure, and output their average to the console
//Loop through the structure again, and contatenate all the values into a long string
//Output the string to the console
//Loop through the string, and count all the 7 [seven] characters; this is like in the game Go Fish when you ask another player, GIMME ALL YOUR SEVENS.
//Output the count to the console
void goFish()
{
    int arrayOfVals[25];
    int sum = 0;
    char concatString[25];
    char intToString[25];
    int i = 0;
    int countOfSeven = 0;
    while (1)
    {
        printf("Enter a number: \n");
        int number;
        scanf("%d", &number); // getting address = getting actual value
        // int number = atoi(enteredNum);
        if (number == -9999)
        {
            break;
        }
        else if (number == 7)
        {
            countOfSeven++;
        }
        printf("NUMBER: %d \n", number);
        arrayOfVals[i] = number;
        sum += number;
        printf("SUM DURING: %d \n", sum);
        sprintf(intToString, "%d", number);
        strcat(concatString, intToString);
        if (sizeof(arrayOfVals) == 25)
        {
            break;
        }
        i++;
    }
    printf("SUM: %d \n", sum);
    printf("AVERAGE: %d \n", (sum / sizeof(arrayOfVals)));
    printf("CONCATENATED STRING: %s \n", concatString);
    printf("NUMBER OF SEVENS: %d \n", countOfSeven); // WORKS
}

int main(int argc, char *argv[])
{
    goFish();
}