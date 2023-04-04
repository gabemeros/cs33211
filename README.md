# cs33211
Operating Systems Assignment 1

Compiled and Ran with :

gcc producer.c -pthread -lrt -o producer
gcc consumer.c -pthread -lrt -o consumer
 ./producer & ./consumer &
 
 
 With implementation of semaphores, producer produces two integers and stores them in the shared memory, between the producer and the consumer.
 Consumer reads in these integers from the shared memory and then removes the two values. Process is repeated for a total of 5 iterations.
 
