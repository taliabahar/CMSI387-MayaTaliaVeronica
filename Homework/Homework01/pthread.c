#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

static void *child(void *ignored) {
    while (1) {
        sleep(5);
        printf("Hey what's up?!\n");
    }
}

int main(int argc, char *argv[]) {
    pthread_t child_thread;
    int code;
    code = pthread_create(&child_thread, NULL, child, NULL);
    if (code) {
       	fprintf(stderr, "pthread_create failed with code %d\n", code);
    }
    char n;
    int result = scanf("%c", &n);
    if( result != 1 || n == '\n') {
        pthread_cancel(child_thread);
        printf("killed child\n");
    }
    return 0;
}