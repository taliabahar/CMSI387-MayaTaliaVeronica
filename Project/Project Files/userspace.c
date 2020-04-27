#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int month, day;
    printf("What month is it? 1-12 \n");
    scanf("%d", &month);
    printf("What day is it? \n");
    scanf("%d", &day);
    long int amma = syscall(335, month, day);
    printf("System call sys_qotd returned %ld\n", amma);
    return 0;
}