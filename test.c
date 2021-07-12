//
// Created by Giuseppe Muschetta on 12/07/21.
//

#include "queue.h"


//simple test of fifo queue data type
int main() {
    queue_t *testQueue = createQueue(3);

    insertNode(testQueue, 23);
    insertNode(testQueue, 17);
    insertNode(testQueue, 15);
    insertNode(testQueue, 18);
    insertNode(testQueue, 77);

    displayQueue(testQueue);
    printf("Queue size is %d\n", testQueue->size);

    sleep(1);

    node_t *gimme = getNode(testQueue);
    displayQueue(testQueue);
    printf("node removed from the head was %d\n",gimme->info);
    printf("queue size now is %d \n", getSize(testQueue));

    sleep(2);


    if(!isEmpty(testQueue)) {
        if (contains(testQueue, 15)) {
            printf("%d has been found in the queue\n", 15);
        }
    }

    sleep(2);

    node_t *gimmme = getNode(testQueue);
    printf("node removed from the head was %d\n",gimmme->info);
    printf("size now is %d\n", getSize(testQueue));
    printf("priority is %d \n", getPriority(testQueue));

    sleep(2);
    int *array = toArray(testQueue);
    printf("displaying the array from the queue: \n");
    displayArray(array, getSize(testQueue));

    sleep(1);

    destroyQueue(testQueue);
    free(array);
    printf("\ncleaning the heap...\n");
    printf("valgrind sould be happy... process terminated!\n");

    return EXIT_SUCCESS;
}
