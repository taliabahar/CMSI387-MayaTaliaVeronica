#include <stdio.h>
/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  File name     :  EvenOddTable.c
 *  Purpose       :  Outputs a table of 3 columns and 20 rows followed by the number of even and odd numbers.
 *                   Column one houses integers -10 to 10. Coulmn two houses the sqaure of the number in column
 *                   on of the same row. Column three houses wether or not the number is even or odd.
 *  Author        :  Talia Bahar, Maya Pegler-Gordon, Veronica Backer Peral 
 *  Date          :  2020-27-20
 *  Description   :  (1)Write a program called evenOddTable.cto vary the value of an integer variable i from 
 *                   -10 to +10 and output a simple table.
 *                   (2)For each value, print i as well as the value of i times i.
 *                   (3)Also print out whether i is even or odd by displaying the word EVEN or ODD at 
 *                   the end of each line.
 *                   (4)Separate the output into columns to make a table using the tab character \t.
 *                   (5)Count the number of EVEN and ODD values, and display the counts at the end of the
 *                   table after a blank line.
 *                   (6)Try to make all the output columns line up neatly. You can decide whether they 
 *                    are left- or right- justified. Left is easier, but right looks nicer for the numbers.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void evenOddTable();

void evenOddTable()
{
    int evenCount = 0;
    int oddCount = 0;
    for (int i = -10; i <= 10; i++)
    {
        printf("%d", i);
        printf("\t");
        printf("%d", i * i);
        printf("\t");
        if (i % 2 == 0)
        {
            printf("EVEN");
            evenCount++;
        }
        else
        {
            printf("ODD");
            oddCount++;
        }
        printf("\n");
    }
    printf("even count is: %d", evenCount);
    printf("odd count is: %d", oddCount);
}

int main(int argc, char *argv[])
{
    evenOddTable();
    return 0;
}