#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int arraySize = atoi(argv[1]);
    // int *a = malloc(arraySize);
    int *a = malloc(sizeof(int) * arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        int r = rand() % 100 + 1;
        a[i] = r;
        if (i == arraySize - 1)
        {
            printf("\n\nthe array is full :) \n\n");
        }
    }
    printf("the value at 1000 is %d \n", a[1000]);
    free(a);
}
