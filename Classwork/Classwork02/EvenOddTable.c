#include <stdio.h>
void evenOddTable();
// char *evenOddTable()
// {
//     char table[100];
//     int evenCount = 0;
//     int oddCount = 0;
//     int index = 0;
//     for (int i = -10; i < 10; i++)
//     {
//         table[index] = i;
//         index++;
//         table[index] = "\t";
//         index++;
//         table[index] = i * i;
//         index++;
//         table[index] = "\t";
//         index++;
//         if (i % 2 == 0)
//         {
//             table[index] = "EVEN";
//             evenCount++;
//             index++;
//         }
//         else
//         {
//             table[index] = "ODD";
//             oddCount++;
//             index++;
//         }
//         table[index] = "\n";
//     }
//     table[index + 1] = "even count is: " + evenCount;
//     table[index + 1] = "odd count is: " + oddCount;
//     return table;
// }

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