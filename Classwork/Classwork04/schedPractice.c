#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

#define TIMESLICE 40;

static void *child(char threadName, int threadDuration)
{
    pthread_t childThread = new Thread(new Runnable()){
        public void run(){
            int remaining = threadDuration;
    int used;
    if (remaining > TIMESLICE)
    {
        used = TIMESLICE;
    }
    else
    {
        used = remaining;
    }

    printf("%s : %d : %d", threadName, used, remaining);
    remaining = remaining - used;
}
}
;
}

int main(int argc, char *argv)
{
    char threadNames[argc / 2];
    int threadDurations[argc / 2];
    int numOfThreads = argc;
    int index = 0;
    for (int i = 0; i < argc; i + 2)
    {
        threadNames[index] = argv[i];
        threadDurations[index] = argv[i + 1];
        index++;
    }
}

//    static void *child(void *ignored){
//       sleep(3);
//       printf("Child is done sleeping 3 seconds.\n");
//       return NULL;
//    }

//    int main(int argc, char *argv[]){
//       pthread_t child_thread;
//       int code;
//       code = pthread_create(&child_thread, NULL, child, NULL);
//       if(code){
//          fprintf(stderr, "pthread_create failed with code %d\n", code);
//       }
//       sleep(5);
//       printf("Parent is done sleeping 5 seconds.\n");
//       return 0;
//    }
