#ifndef OS_ASSIGNMENT_ONE
#define OS_ASSIGNMENT_ONE


#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int maxTableSize = 2;
int iterations = 5;

struct table {
    sem_t filledSpots;
    sem_t emptySpots;
    int sharedBuffer[2];

};

#endif

