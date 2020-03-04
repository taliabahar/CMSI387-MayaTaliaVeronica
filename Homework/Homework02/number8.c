// Write a program that loops many times, each time using an inner loop to access every 4096th element
// of a large array of bytes. Time how long your program takes per array access. Do this with varying
// array sizes. Are there any array sizes when the average time suddenly changes?
// Write a report in which you explain what you did, and the hardware and software system context
//  in which you did it, carefully enough that someone could replicate your results.

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf(" Array Size |  Time to Access |  Value at 4096 \n");
    for (int j = 4096; j < 100000; j++)
    {
        int arraySize = j;
        int *a = malloc(sizeof(int) * arraySize);
        for (int i = 0; i < arraySize; i++)
        {
            int r = rand() % 100 + 1;
            a[i] = r;
            // if (i == arraySize - 1)
            // {
            //     printf("\n\nthe array is full :) \n\n");
            // }
        }
        clock_t t;
        t = clock();
        int valueAtIndex = a[4096];
        t = clock() - t;
        double timeToAccess = ((double)t) / CLOCKS_PER_SEC;
        if (timeToAccess >= .00001)
        {
            printf("Array Size: %d |", arraySize);
            printf("Time to Access: %f| Value at Index 4096: %d \n", timeToAccess, valueAtIndex);
        }
        free(a);
    }
}