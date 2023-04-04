//Gabe Meros
// cs33211
// Producer file for assignment 1


#include "table.h"
#include "string.h"
#include "errno.h"


int main(int argc, char* argv[]) {
    srand(time(nullptr)); // random seed

    int shared =shm_open("/SharedMemory2", O_CREAT | O_RDWR, S_IXUSR | S_IRUSR | S_IWUSR);
    if(shared == -1)
    printf("error: shm_open()");



if(ftruncate(shared, sizeof(struct table)) == -1)
printf("error: resizef()");
else
ftruncate(shared, sizeof(struct table)); // resize shared memory

struct table *producer;
producer = static_cast<table*>(mmap(0, sizeof(struct table), PROT_READ|PROT_WRITE, MAP_SHARED, shared, 0)); //point to shared memory

if (producer == MAP_FAILED)
    printf("error: mmap()");


//Initializde semaphores
sem_init(&(producer->emptySpots), 1, maxTableSize);
sem_init(&(producer->filledSpots), 1, 0);

for(int i = 0; i < maxTableSize; ++i) {
    producer->sharedBuffer[i] = 0;
}


int turn = 0;
while(turn < iterations) { //5 iterations

while (producer->sharedBuffer[0] != 0 && producer->sharedBuffer[1] != 0); // busy wait until consumer finishes

sleep(1);
sem_wait(&producer->emptySpots);

int filler;
for(int i = 0; i < maxTableSize; ++i) {
    filler = rand() % 100 + 1; //create filler to fill spot
    if(filler == 0) {
        filler = 1;
    }
    producer->sharedBuffer[i] = filler;
    printf("producer produced %d ", filler);
}
++turn;

sem_post(&producer->filledSpots);
}

return 0;

}