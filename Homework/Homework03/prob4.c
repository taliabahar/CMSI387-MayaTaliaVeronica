// Write a program that opens a file in read-only mode and maps the entire file into the virtual-memory address space using mmap.
// The program should search through the bytes in the mapped region, testing whether any of them is equal to the character X.
// As soon as an X is found, the program should print a success message and exit.
// If the entire file is searched without finding an X, the program should report failure.
// Time your program on files of varying size, some of which have an X at the beginning, while others have an X only at the end or not at all.

//Run using ./a.out test.txt
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {

        return -1;
    }

    int fd_in = open(argv[1], O_RDONLY);
    if (fd_in < 0)
    {

        perror(argv[1]);

        return -1;
    }

    struct stat info;
    if (fstat(fd_in, &info) < 0)
    {

        perror("Error stating input file");

        return -1;
    }

    void *addr_in = mmap(0, info.st_size, PROT_READ, MAP_SHARED, fd_in, 0);

    if (addr_in == MAP_FAILED)
    {
        perror("Error mapping input file");
        return -1;
    }

    char *asChar = (char *)addr_in;
    int dataSize = info.st_size / sizeof(asChar[0]);
    // int dataSize = sizeof(info.st_size) / sizeof(asChar[0]);

    for (int i = 0; i < dataSize; i++)
    {
        if (asChar[i] == 'X')
        {
            printf("Success! Found X. \n");
            return 0;
        }
    }
    printf("Failure! X was not found. \n");
    return 0;
}
