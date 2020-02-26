#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#define TIMESLICE 40;

struct args
{
    char *threadName;
    int threadDuration;
}

static void *
child(void *input)
{
    char name = ((struct args *)input)->threadName;
    int remaining = ((struct args *)input)->threadDuration;
    int used = 0;
    while (1)
    {
        if (remaining > TIMESLICE)
        {
            used = TIMESLICE;
        }
        else
        {
            used = remaining;
        }
        printf("%s : %d : %d", name, used, remaining);
        remaining = remaining - used;
        sleep(used);
    }
}
int main(int argc, char *argv)
{
    char threadNames[argc - 1 / 2];
    int threadDurations[argc - 1 / 2];
    int numOfThreads = argc - 1;
    int index = 0;
    for (int i = 0; i < argc; i + 2)
    {
        threadNames[index] = argv[i];
        threadDurations[index] = argv[i + 1];
        index++;
    }
    struct args *A = (struct args *)malloc(sizeof(struct args));
    char A = "A";
    A->threadName = threadNames[0];
    A->threadDuration = threadDurations[0];

    struct args *B = (struct args *)malloc(sizeof(struct args));
    char B = "B";
    B->threadName = threadNames[1];
    B->threadDuration = threadDurations[1];

    struct args *C = (struct args *)malloc(sizeof(struct args));
    char C = "C";
    C->threadName = threadNames[2];
    C->threadDuration = threadDurations[2];

    struct args *D = (struct args *)malloc(sizeof(struct args));
    char D = "D";
    D->threadName = threadNames[3];
    D->threadDuration = threadDurations[3];

    pthread_t threadA;
    pthread_create(&threadA, NULL, child, (void *)A);

    pthread_t threadB;
    pthread_create(&threadB, NULL, child, (void *)B);

    pthread_t threadC;
    pthread_create(&threadC, NULL, child, (void *)C);

    pthread_t threadD;
    pthread_create(&threadD, NULL, child, (void *)D);
}

// static void *child(char threadName, int threadDuration)
// {
// pthread_t childThread = new Thread(new Runnable()){
//     public void run(){
//       int remaining = threadDuration;
//       int used;
//       if (remaining > TIMESLICE)
//       {
//         used = TIMESLICE;
//       } else {
//         used = remaining;
//       }
//         printf("%s : %d : %d", threadName, used, remaining);
//         remaining = remaining - used;
//     }
// };
// }

//childThread.start() - runs runnable code once thread is created

//int main(int argc, char *argv)
// {
//     char threadNames[argc - 1 / 2];
//     int threadDurations[argc - 1 / 2];
//     int numOfThreads = argc - 1;
//     int index = 0;
//     for (int i = 0; i < argc; i + 2)
//     {
//         threadNames[index] = argv[i];
//         threadDurations[index] = argv[i + 1];
//         index++;
//     }
//     pthread_t child_thread;
//     int code;
//     code = pthread_create(&child_thread, NULL, child, NULL);
//     if (code)
//     {
//         fprintf(stderr, "pthread_create failed with code %d\n", code);
//     }
// }