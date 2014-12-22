#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/resource.h>

#define ARRAY_SIZE 1000
#define MB 1024*1024

double time_array[ARRAY_SIZE];

void printArray()
{
    int index;
    for (index = 0; index < ARRAY_SIZE; index++) {
        printf("%lf\n", time_array[index]);
    }
}

int main(int argc, char *argv[])
{
    long memblock_size = MB;
    memblock_size *= atoi(argv[1]);
    int* memptr = (int*)(malloc(memblock_size));
    int* tmp;
    int iteration = 0;
    int num = 0;

    struct timespec ts_start;
    struct timespec ts_end;

    while(1) 
    {
        int value;
        int iteration = 0;
        clock_gettime(CLOCK_MONOTONIC, &ts_start);

        while (iteration < 20) {
            tmp = memptr;
            value = iteration%2;
            while (tmp < (memptr + (memblock_size/4))) {
                // Write on the first word of every page
                *tmp = value;
                // Jump one page
                tmp = tmp + 1024;
            }
            iteration++;
        }

        clock_gettime(CLOCK_MONOTONIC, &ts_end);
        double start = ((double) ts_start.tv_sec * 1000000000) + ts_start.tv_nsec;
        double end = ((double) ts_end.tv_sec * 1000000000) + ts_end.tv_nsec;
    }

    printArray();
    return 0;
}
