//
// Created by Giuseppe Muschetta on 12/07/21.
//

#ifndef MFQ_SCHEDULING_ALGO_QUEUE_H
#define MFQ_SCHEDULING_ALGO_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <sys/un.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>


#define ec_null(a)       \
        if( (a) == NULL){  \
            fprintf(stderr,"memory allocation failed at %d line\n",__LINE__); \
            exit(EXIT_FAILURE);                   \
        }


//un nodo di una coda:
typedef struct node_{
    int info;
    struct node_ *next;
}node_t;

//il tipo dato coda:
typedef struct queue_{
    node_t *head;
    node_t *tail;
    int size;
    int priority;
}queue_t;


//INTERFACE METHODS:
queue_t *createQueue(int priority);
void destroyQueue(queue_t *q);
bool insertNode(queue_t *q, int info);
node_t *getNode(queue_t *q);
bool isEmpty(queue_t *q);
int getSize(queue_t *q);
bool contains(queue_t *q, int info);
int *toArray(queue_t *q);
int getPriority(queue_t *q);

//AUX METHODS:
node_t *createNode(int info); //for insertNode()
void destroyNode(node_t *node);
void displayQueue(queue_t *q);
void displayArray(int *array, int dim);


#endif //MFQ_SCHEDULING_ALGO_QUEUE_H
