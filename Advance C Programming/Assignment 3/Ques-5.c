#include <stdio.h>
#include <pthread.h>


void *printHello(void *arg) {
    printf("Hello ");
    pthread_exit(NULL);
}


void *printWorld(void *arg) {
    printf("World\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;


    if (pthread_create(&thread1, NULL, printHello, NULL) != 0) {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }


    pthread_join(thread1, NULL);


    if (pthread_create(&thread2, NULL, printWorld, NULL) != 0) {
        fprintf(stderr, "Error creating thread 2\n");
        return 2;
    }


    pthread_join(thread2, NULL);

    return 0;
}
