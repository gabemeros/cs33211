//Gabe Meros
//CS33211
//Consumer file for assignment 1


#include "table.h"

int main() {
    //producer.c has shared initialized

    int shared = shm_open("/SharedMemory2", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if(shared == -1)
    printf("error: shm_open()");

    struct table *consumer;
    consumer = static_cast<table*>(mmap(0, sizeof(struct table), PROT_READ | PROT_WRITE, MAP_SHARED, shared, 0));
    if(consumer == MAP_FAILED)
    printf("error: mmap()");

    int turn = 0;
    while ( turn < iterations) { // 5 iterations
    
    while(consumer->sharedBuffer[0] == 0 && consumer->sharedBuffer[1] == 0); //busy wait for producer to finish filling table

    sleep(1);
    sem_wait(&consumer->filledSpots);

    for (int i=0; i < maxTableSize; ++i) {
        printf("consumer removed %d", consumer->sharedBuffer[i]);
        consumer->sharedBuffer[i] = 0; // replace removed number
    }

    ++turn;
    printf("Turn: %i ", turn);
    sem_post(&consumer->emptySpots);

    }

    return 0;

}
    

