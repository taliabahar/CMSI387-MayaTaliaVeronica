/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  File name     :  pthread.c
 *  Purpose       :  Runs a thread that sleeps then prints a message until the enter key is pressed.  
 *  Author        :  Talia Bahar, Maya Pegler-Gordon, Veronica Backer Peral 
 *  Date          :  2020-02-4
 *  Description   :  This program creates a second thread in the initial (main) thread. THe main thread sits
 *                   on a read call waiting until the user presses the Enter key. At that point, it should 
 *                   kill off the second thread and print out a message reporting that it has done so.
 *                   Meanwhile, the second thread should be in an infinite loop, each time around
 *                   sleeping five seconds and then printing out "Hey what's up?!".
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

static void *child(void *ignored)
{
    while (1)
    {
        sleep(5);
        printf("Hey what's up?!\n");
    }
}

int main(int argc, char *argv[])
{
    pthread_t child_thread;
    int code;
    code = pthread_create(&child_thread, NULL, child, NULL);
    if (code)
    {
        fprintf(stderr, "pthread_create failed with code %d\n", code);
    }
    char n;
    int result = scanf("%c", &n);
    if (result != 1 || n == '\n')
    {
        pthread_cancel(child_thread);
        printf("killed child\n");
    }
    return 0;
}